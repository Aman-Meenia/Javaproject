package Display_All_Data;
import java.util.*;

public class Updatedata {
    public
    static HashMap<String,Integer> Bookeddata= new HashMap<>();
    public
    static  HashMap<String,Integer> mpprice= new HashMap<>();
    public
    static  HashMap<String, Integer> mpticket= new HashMap<>();
    String name;
    int ticket,price;
    public Updatedata(){

    }
// to upadte the new movie
   public Updatedata(String name, int ticket, int price){
        this.name = name;
        this.price= price;
        this.ticket=ticket;
        if(mpprice.containsKey(name)){
            int previousticket= mpticket.get(name);
            mpticket.put(name, ticket);
        }
       mpprice.put(name, price);
       mpticket.put(name, ticket);



    }
//     To increase no of tickets
    public  Updatedata(String name , int ticket){
        int previousticket= mpticket.get(name);
        previousticket+=ticket;
        mpticket.put(name,previousticket);
        int tttt = mpticket.get(name);
    }
// To display all data
    public
      void showalldata() {
        for(Map.Entry<String,Integer> it : mpprice.entrySet()){
String t = it.getKey();
int Tprice = it.getValue();
int Tticket = mpticket.get(t);
            System.out.println("Name: "+ t +" , Price: " + Tprice +" , Ticket: "+ Tticket);

      }
      }




}



