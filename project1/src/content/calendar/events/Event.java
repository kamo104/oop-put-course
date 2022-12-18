package content.calendar.events;

import java.time.LocalDateTime;

import content.constants.Constants;

public interface Event {
    public long duration();
    public LocalDateTime date();
    public String note();
    public boolean canTakePatient();

    public final class Default implements Event{
        @Override
        public long duration(){
            return Constants.appointmentLength;
        }

        @Override
        public LocalDateTime date(){
            return LocalDateTime.now();
        }

        @Override 
        public String note(){
            return "";
        }
        
        @Override
        public boolean canTakePatient(){
            return false;
        }
    }
}
