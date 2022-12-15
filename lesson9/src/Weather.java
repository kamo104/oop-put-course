import java.time.LocalDateTime;

public class Weather {
    private final Forecast forecast;
    private final String temperatureScale;
    public Weather(Forecast forecast, String temperatureScale){
        this.temperatureScale = temperatureScale;
        this.forecast = forecast;
    }
    public String temperatureNow(){
        String oputput = Float.toString(this.forecast.temperature(LocalDateTime.now(), this.temperatureScale));
        return oputput+" "+this.temperatureScale;
    }
}
