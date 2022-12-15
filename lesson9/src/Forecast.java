import java.time.LocalDateTime;

public interface Forecast {
    public float temperature(LocalDateTime day, String temperatureScale);
    
    public final class Fake implements Forecast{
        @Override
        public float temperature(LocalDateTime day, String temperatureScale){
            return 0f;
        }
    }
}
