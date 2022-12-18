package content.calendar;



import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

import content.calendar.events.Event;
import content.constants.Constants;


public class Calendar {

    
    private ArrayList<Event> events = new ArrayList<Event>();

    public boolean addEvent(Event event){
        return this.events.add(event);
    }

    public ArrayList<Event> duringDateFrame(LocalDateTime startDate, LocalDateTime endDate){
        long startDateEpochSeconds = startDate.toEpochSecond(ZoneId.systemDefault().getRules().getOffset(startDate));
        long endDateEpochSeconds = endDate.toEpochSecond(ZoneId.systemDefault().getRules().getOffset(endDate));

        ArrayList<Event> events = new ArrayList<Event>();
        for(Event ev : this.events){
            long eventStartEpochSeconds = ev.date().toEpochSecond(ZoneId.systemDefault().getRules().getOffset(ev.date()));
            long eventEndEpochSeconds = ev.date().plus(ev.duration(), ChronoUnit.SECONDS).toEpochSecond(ZoneId.systemDefault().getRules().getOffset(ev.date()));
            
            // case 1: event starts later than the startDate and before the endDate
            // case 2: event start sooner than the startDate but ends after it
            if(startDateEpochSeconds < eventStartEpochSeconds && endDateEpochSeconds > eventStartEpochSeconds) events.add(ev);
            else if(startDateEpochSeconds > eventStartEpochSeconds && startDateEpochSeconds < eventEndEpochSeconds) events.add(ev);
        }
        return events;
    }

    public ArrayList<Event> events(){
        return this.events;
    }

    public Calendar(){
    };
    public Calendar(ArrayList<Event> events){
        this.events = events;
    }
    public Calendar(Event event){
        this.events.add(event);
        this.events = events;
    }

}
