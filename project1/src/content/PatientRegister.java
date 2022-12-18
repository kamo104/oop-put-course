package content;

import java.util.ArrayList;

public class PatientRegister {
    private ArrayList<Patient> patients = new ArrayList<Patient>();

    public boolean registerPatient(String patientName, String patientLastname, long patientId, PhoneNumber patientPhoneNumber){
        return this.patients.add(new Patient(patientName, patientLastname, patientId, patientPhoneNumber));
    }
    public boolean registerPatient(Patient patient){
        return this.patients.add(patient);
    }
    public boolean isPatientRegistered(Patient patient){
        for(Patient pat : patients) if(pat == patient) return true;

        return false;
    }
    public boolean patientId(Name patientName, PhoneNumber patientPhoneNumber){
        for(Patient patient : patients) if(patient.name() == patientName.fullname() && patient.phoneNumber() == patientPhoneNumber.number()) return true;
        
        return false;
    }
    public Patient patient(long patientId){
        for(Patient patient : patients) if(patient.id() == patientId) return patient;

        throw new Error("No patient with Id: " +patientId+ " found");
    }

    public PatientRegister(ArrayList<Patient> patients){
        this.patients = patients;
    }
}
