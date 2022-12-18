
import content.*;
import config.Loader;

import content.calendar.*;
import content.calendar.events.*;
// import content.calendar.Calendar;

import java.util.ArrayList;
import java.io.IOException;
import java.time.format.DateTimeFormatter;

class Main{
    public static void main(String[] args){
        // try to read in the patients
        ArrayList<Patient> pList = new ArrayList<Patient>();
        try{
            pList = Loader.patients();
        }
        catch(IOException exception){
            System.out.println("Could not open patients.txt");
            return;
        }
        PatientRegister patientRegister = new PatientRegister(pList);

        // try to read in the doctors
        ArrayList<Doctor> dList = new ArrayList<Doctor>();
        try{
            dList = Loader.doctors();
        }
        catch(IOException exception){
            System.out.println("Could not open doctors.txt");
            return;
        }
        AppointmentPlanner appointmentPlanner = new AppointmentPlanner(dList);

        // planning an Appointment
        AppointmentInfo appointmentInfo = appointmentPlanner.nearestAppointment();

        // patient of which Id will go to that appointment
        appointmentInfo.patient = patientRegister.patient(0);

        // finally confirm the planned appointment
        boolean success = appointmentPlanner.planAppointment(appointmentInfo, "Appointment Note");

        DateTimeFormatter formatter = DateTimeFormatter.ISO_DATE_TIME;
        // System.out.println(appointmentInfo.doctor.name());
        ArrayList<Appointment> plannedAppointments = appointmentPlanner.plannedAppointments();
        for(Appointment appointment : plannedAppointments){
            System.out.println();
            System.out.println("Doctor's name: " + appointment.doctor().name());
            System.out.println("Patient's name: " + appointment.patient().name());
            System.out.println("Appointment date: " + appointment.date().format(formatter));
        }
        
    }
}