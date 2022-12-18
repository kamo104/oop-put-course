package content;


import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

import content.calendar.Calendar;
import content.calendar.events.Event;
import content.calendar.events.WorkEvent;
import content.constants.Constants;
import content.calendar.AppointmentInfo;
import content.calendar.events.Appointment;

public class Doctor implements Person{
    private Calendar calendar;

    private long id;
    private Name name;
    private PhoneNumber phoneNumber;

    public String phoneNumber(){
        return this.phoneNumber.number();
    }
    public long id(){
        return this.id;
    }
    public String name(){
        return this.name.fullname();
    }
    
    public AppointmentInfo nextAvailableAppointment(LocalDateTime date){

        //find next open appointment window
        while(this.isAvailable(date = date.plus(Constants.searchWindow, ChronoUnit.SECONDS)) == false);
        
        return new AppointmentInfo(date, Constants.appointmentLength, this, null);
    }
    public boolean scheduleEvent(Event event){
        return this.calendar.addEvent(event);
    }

    private boolean isAvailableOnDate(LocalDateTime date, long eventDuration){
        // long eventDuration = Constants.appointmentLength;
        // if(appointmentDuration.length>0) eventDuration = appointmentDuration[0];

        // if at work and no patient coliding
        ArrayList<Event> eventsOnTimeFrame = this.calendar.duringDateFrame(date, date.plus(eventDuration, ChronoUnit.SECONDS));
        
        WorkEvent workOnThatDate = new WorkEvent();
        boolean worksOnThatDate = false;
        // check for work events during that date
        for(Event ev : eventsOnTimeFrame) if(ev instanceof WorkEvent) {
            worksOnThatDate = true;
            workOnThatDate = (WorkEvent)ev;
        }

        // 1. if he doesn't work during this date
        if(worksOnThatDate == false) return false;

        // 2. if his work starts later than the date
        if(
            workOnThatDate.date().toEpochSecond(ZoneId.systemDefault().getRules().getOffset(workOnThatDate.date())) > 
            date.toEpochSecond(ZoneId.systemDefault().getRules().getOffset(date))
        ) return false;

        // 3. if his work ends before the event ends
        if(
            workOnThatDate.date().toEpochSecond(ZoneId.systemDefault().getRules().getOffset(workOnThatDate.date())) + workOnThatDate.duration() < 
            date.toEpochSecond(ZoneId.systemDefault().getRules().getOffset(date)) + eventDuration
        ) return false;

        // 4. check for events during the date - Constants.restBetweenAppointments : date + Constants.restBetweenAppointments 
        //    that disable the doctor from taking in patients
        ArrayList<Event> eventsInBusyPeriod = this.calendar.duringDateFrame(
            date.plus(-Constants.restBetweenAppointments, ChronoUnit.SECONDS), 
            date.plus(Constants.restBetweenAppointments, ChronoUnit.SECONDS)
        );
        for(Event ev : eventsInBusyPeriod) if(ev.canTakePatient() == false) return false;



        return true;
    }

    public <T> boolean isAvailable(T date){
        if(date instanceof LocalDateTime) return this.isAvailableOnDate((LocalDateTime)date, Constants.appointmentLength);
        else if(date instanceof Event) return this.isAvailableOnDate((LocalDateTime)date, ((Event)date).duration());
        return false;
    }

    public ArrayList<Appointment> scheduledAppointments(){
        ArrayList<Appointment> appointments = new ArrayList<Appointment>();
        for(Event event : this.calendar.events()) if(event instanceof Appointment) appointments.add((Appointment)event);
        return appointments;
    }

    public Doctor(String firstname, String lastname, long id, PhoneNumber phoneNumber, Calendar calendar){
        this.name = new Name(firstname, lastname);
        this.id = id;
        this.phoneNumber = phoneNumber;

        this.calendar = calendar;
    }
    public Doctor(Name name, long id, PhoneNumber phoneNumber, Calendar calendar){
        this.name = name;
        this.id = id;
        this.phoneNumber = phoneNumber;

        this.calendar = calendar;
    }
}
