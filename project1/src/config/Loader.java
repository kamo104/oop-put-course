package config;

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

import content.Patient;
import content.PhoneNumber;
import content.calendar.Calendar;
import content.calendar.events.WorkEvent;
import content.Doctor;
import content.Name;

public class Loader {
    public static ArrayList<Patient> patients() throws IOException{
        ArrayList<Patient> patients = new ArrayList<Patient>();

        BufferedReader reader = new BufferedReader(new FileReader("config/patients.txt"));
        String currentLine = reader.readLine();
        
        int numberOfPatients = Integer.parseInt(currentLine);
        for(int i=0;i<numberOfPatients;i++){
            currentLine = reader.readLine();
            int readField = 0;
            String[] splited = currentLine.split(" ");
            Name name = new Name(splited[readField++],splited[readField++]);
            long id = Long.parseLong(splited[readField++]);

            ArrayList<Integer> numbersInPhoneNumber = new ArrayList<Integer>();
            
            for(int j=0;j<9;j++) numbersInPhoneNumber.add(Character.getNumericValue(splited[readField].charAt(j)));
            
            PhoneNumber phoneNumber = new PhoneNumber(numbersInPhoneNumber);
            patients.add(new Patient(name, id, phoneNumber));
        }   

        reader.close();
        return patients;
    }
    public static ArrayList<Doctor> doctors() throws IOException{
        ArrayList<Doctor> doctors = new ArrayList<Doctor>();

        BufferedReader reader = new BufferedReader(new FileReader("config/doctors.txt"));
        String currentLine = reader.readLine();
        
        int nDoctors = Integer.parseInt(currentLine);
        for(int i=0;i<nDoctors;i++){
            currentLine = reader.readLine();
            int readField = 0;
            String[] splited = currentLine.split(" ");

            Name name = new Name(splited[readField++],splited[readField++]);
            long id = Long.parseLong(splited[readField++]);

            ArrayList<Integer> numbersInPhoneNumber = new ArrayList<Integer>();
            for(int j=0;j<9;j++) numbersInPhoneNumber.add(Character.getNumericValue(splited[readField].charAt(j)));
            
            PhoneNumber phoneNumber = new PhoneNumber(numbersInPhoneNumber);


            Calendar calendar = new Calendar();
            LocalDateTime startingDate = LocalDateTime.of(
                LocalDateTime.now().getYear(), 
                LocalDateTime.now().getMonth(), 
                LocalDateTime.now().getDayOfMonth()+1, 
                8, 
                0
            );
            for(int j=0;j<9;j++) calendar.addEvent(new WorkEvent(startingDate.plus(j*86400, ChronoUnit.SECONDS)));

            doctors.add(new Doctor(name, id, phoneNumber, calendar));
        }   

        reader.close();
        return doctors;
    }
}
