package content.calendar.events;
import java.time.LocalDateTime;

import content.constants.Constants;

public class WorkEvent implements Event{
    private LocalDateTime date;
    private String note = new String("");
    private long duration = Constants.defaultWorktime;

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
        return true;
    }

    public WorkEvent(LocalDateTime date, long duration, String... note){
        if(note.length>0) this.note = note[0];

        this.date = date;
        this.duration = duration;

    }
    public WorkEvent(LocalDateTime date, String... note){
        if(note.length>0) this.note = note[0];

        this.date = date;
    }
    public WorkEvent(){
        this.date = LocalDateTime.now();
        
    }
}
