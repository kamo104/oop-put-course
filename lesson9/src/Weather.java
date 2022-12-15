
import java.time.LocalDateTime;

public class Weather {
    private final Forecast forecast;
    private final String temperatureScale;
    public Weather(Forecast forecast, String temperatureScale){
        this.temperatureScale = temperatureScale;
        this.forecast = forecast;
    }
    public String temperatureNow(){
        return String.valueOf(this.forecast.temperature(LocalDateTime.now(), this.temperatureScale))+" "+this.temperatureScale;
    }
}
