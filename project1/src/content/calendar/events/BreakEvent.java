package content.calendar.events;
import java.time.LocalDateTime;

import content.constants.Constants;

public class BreakEvent implements Event {
    private LocalDateTime date;
    private String note = new String("");
    private long duration = Constants.defaultBreakDuration;

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

    public BreakEvent(LocalDateTime date, long duration, String... note){
        if(note.length>0) this.note = note[0];
        // else this.note = new String("");

        this.date = date;
        this.duration = duration;

    }
    public BreakEvent(){
        this.date = LocalDateTime.now();

        
    }
}
