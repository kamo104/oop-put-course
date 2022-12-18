package content;

public class Name {
    private String firstname;
    private String lastname;
    public String fullname(){
        return this.firstname + " " + this.lastname;
    }
    public Name(String firstname, String lastname){
        this.firstname = firstname;
        this.lastname = lastname;
    }
}
