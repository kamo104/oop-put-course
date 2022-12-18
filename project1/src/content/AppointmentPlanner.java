package content;

import java.util.ArrayList;

import content.calendar.events.*;
import content.calendar.*;

import java.time.LocalDateTime;
import java.time.ZoneId;

public class AppointmentPlanner {
    // private PatientRegister patientRegister;
    private ArrayList<Doctor> doctors;

    public AppointmentInfo nearestAppointment(){
        // list all nearest appointments from doctors
        ArrayList<AppointmentInfo> appointments = new ArrayList<AppointmentInfo>();
        for(Doctor doctor : this.doctors){
            AppointmentInfo info = this.nearestAppointment(doctor);
            appointments.add(info);
        }

        // find nearest appointment of all of them
        AppointmentInfo nearestPossibleAppointment = appointments.get(0);
        for(AppointmentInfo info : appointments){
            if(
                info.date.toEpochSecond(ZoneId.systemDefault().getRules().getOffset(info.date)) < 
                nearestPossibleAppointment.date.toEpochSecond(ZoneId.systemDefault().getRules().getOffset(nearestPossibleAppointment.date))
            )
            nearestPossibleAppointment = info;
        }
    
        return nearestPossibleAppointment;
    }

    public AppointmentInfo nearestAppointment(String doctorName, String doctorPhonenumber) throws Error{
        Doctor findDoctor=null;
        for(Doctor doctor : this.doctors){
            if(doctor.name() == doctorName && doctorPhonenumber == doctor.phoneNumber()) findDoctor = doctor;
        }

        if(findDoctor==null) throw new Error("No doctor named: " + doctorName + " found");
        return this.nearestAppointment(findDoctor);
    }

    public AppointmentInfo nearestAppointment(long doctorId) throws Error{
        Doctor findDoctor=null;
        for(Doctor doctor : this.doctors){
            if(doctor.id() == doctorId) findDoctor = doctor;
        }

        if(findDoctor==null) throw new Error("No doctor with id: " + doctorId + " found");
        return this.nearestAppointment(findDoctor);
    }

    public AppointmentInfo nearestAppointment(Doctor doctor){
        return doctor.nextAvailableAppointment(LocalDateTime.now());
    }

    



    public boolean planAppointment(AppointmentInfo appointmentInfo, String note){
        for(Doctor doctor : this.doctors){
            if(doctor.id()!=appointmentInfo.doctor.id()) continue;

            Appointment appointment = new Appointment(appointmentInfo.date, appointmentInfo.duration, doctor, appointmentInfo.patient, note);
            doctor.scheduleEvent(appointment);
            return true;
        }

        return false;
    }

    public ArrayList<Appointment> plannedAppointments(){
        ArrayList<Appointment> appointments = new ArrayList<Appointment>();
        for(Doctor doctor : this.doctors) appointments.addAll(doctor.scheduledAppointments());
        return appointments;
    }


    public AppointmentPlanner(ArrayList<Doctor> doctors){
        this.doctors = doctors;
    };
}
