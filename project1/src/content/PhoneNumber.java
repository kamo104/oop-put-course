package content;

import java.util.ArrayList;

public class PhoneNumber {
    private ArrayList<Integer> numbers;

    public String number(){
        String phoneNumber = new String();
        int i=0;
        for(int num : numbers){
            if(i%3==2){
                i=0;
                phoneNumber += " ";
            }
            phoneNumber += Integer.toString(num);
        }
        return phoneNumber;
    }
    public PhoneNumber(ArrayList<Integer> numbers){
        this.numbers = new ArrayList<Integer>(numbers);
    }
}
