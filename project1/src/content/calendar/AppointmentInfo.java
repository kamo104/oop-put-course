package content.calendar;


import java.time.LocalDateTime;
import content.*;

public class AppointmentInfo {
    public Patient patient;
    public Doctor doctor;
    public LocalDateTime date;
    public long duration;


    public AppointmentInfo(LocalDateTime date, long duration, Doctor doctor, Patient patient){
        this.date = date;
        this.duration = duration;
        
        this.doctor = doctor;
        this.patient = patient;
    }
    public AppointmentInfo(AppointmentInfo appointmentInfo, Patient patient){
        this.date = appointmentInfo.date;
        this.duration = appointmentInfo.duration;
        
        this.doctor = appointmentInfo.doctor;
        this.patient = patient;
    }
}
