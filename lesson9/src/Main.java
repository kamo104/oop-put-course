public class Main {
    public static void main (String[] args){
        
        Forecast forecast = new Forecast.Fake();
        Weather weather = new Weather(forecast, "Celcius");
        System.out.println(weather.temperatureNow());
        // assert 
        assert "0 Celcius".equals(weather.temperatureNow());
    }
}