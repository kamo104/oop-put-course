package content.calendar.events;

import java.time.LocalDateTime;
import content.Patient;
import content.Doctor;

public class Appointment implements Event{
    private Doctor doctor;
    private Patient patient;
    private LocalDateTime date;
    private String note;
    private long duration;

    public Doctor doctor(){
        return this.doctor;
    }
    public Patient patient(){
        return this.patient;
    }
    public long duration(){
        return this.duration;
    }
    public LocalDateTime date(){
        return this.date;
    }
    public String note(){
        return this.note;
    }
    public boolean canTakePatient(){
        return false;
    }

    public Appointment(LocalDateTime date, long duration, Doctor doctor, Patient patient, String... note){
        if(note.length>0) this.note = note[0];
        else this.note = new String("");

        this.doctor = doctor;
        this.patient = patient;
        this.date = date;
        this.duration = duration;
        
    }
    
    
}
