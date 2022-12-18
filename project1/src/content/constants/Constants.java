package content.constants;

public class Constants {
    public static long appointmentLength = 20*60; // in seconds
    public static long restBetweenAppointments = 5*60;
    public static long searchWindow = appointmentLength + 2*restBetweenAppointments;
    public static long defaultWorktime = 8*60*60;
    public static long defaultBreakDuration = 15*60;
}
