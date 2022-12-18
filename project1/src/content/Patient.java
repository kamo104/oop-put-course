package content;

public class Patient implements Person{
    private long id;
    private Name name;
    // private String name;
    // private String lastname;
    private PhoneNumber phoneNumber;

    public String phoneNumber(){
        return this.phoneNumber.number();
    }
    public long id(){
        return this.id;
    }
    public String name(){
        return this.name.fullname();
    }
    public Patient(String firstname, String lastname, long id, PhoneNumber phoneNumber){
        this.name = new Name(firstname, lastname);
        this.id = id;
        this.phoneNumber = phoneNumber;
    }
    public Patient(Name name, long id, PhoneNumber phoneNumber){
        this.name = name;
        this.id = id;
        this.phoneNumber = phoneNumber;
    }
}
