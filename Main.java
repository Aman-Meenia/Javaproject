package com.javacode;

import Display_All_Data.*;

import java.sql.SQLOutput;
import java.util.*;

interface BOOK {

    abstract void bookticket(String s, int t);
}

class Bookedticket extends Updatedata implements BOOK {


    public void bookticket(String s, int t) {

        int leftticket = mpticket.get(s);
        if (leftticket >= t) {
            int k = leftticket - t;
            mpticket.put(s, k);
            if (Bookeddata.containsKey(s)) {
                int temp = Bookeddata.get(s);
                Bookeddata.put(s, temp + t);
            } else {
                Bookeddata.put(s, t);
            }
            System.out.println("             *********** Tickets Succesfully Booked *********** ");
        } else {
            System.out.println("Only  " + leftticket + " Tickets are left , So we cannot book Tickets  ");
        }


    }


}

class displaybookeddata extends Updatedata {
    public void display() {
        int totalprice = 0;
        System.out.println("BOOKED TICKETS ARE ------->>>>>>>>");
        for (Map.Entry<String, Integer> it : Bookeddata.entrySet()) {
            String tname = it.getKey();
            int ticketsbuy = it.getValue();
            int priceofoneticket = mpprice.get(tname);
            System.out.println("Name is " + tname + " , Tickets " + ticketsbuy + " , price " + priceofoneticket);
            totalprice += priceofoneticket * ticketsbuy;

        }
        System.out.println("Total Price : RS. " + totalprice + "/-");
    }
}


public class Main {


    public static void main(String[] args) {
        // write your code here


        Scanner Sc = new Scanner(System.in);
        System.out.println("           <----------WELCOME TO BOOK MY SHOW ---------->        ");
        System.out.println();
        System.out.println("    PLEASE SELECT ONE OF THESE OPTION ---> ");
        System.out.println("   ->  FOR UPDATING THE DATA OF MOVIES PRESS 1");
        System.out.println("   ->  FOR BOOKING THE TICKET PRESS 2");
        System.out.println("   ->  FOR INCREASING THE NUMBER OF TICKETS OF ALREADY PRESENT MOVIES PRESS 3");
        System.out.println("   ->  FOR DISPLAYING DATA OF BOOKED MOVES PRESS 4");
        System.out.println("   ->  FOR EXIT ENTER ANY NUMBER EXCEPT 1,2,3 AND 4");
        System.out.println();
        int cnd;
        cnd = Sc.nextInt();
        while (cnd >= 0 && cnd <= 4) {

// for updating the data
            if (cnd == 1) {

                System.out.println("Enter the number of movies ");
                int n;
                n = Sc.nextInt();
                for (int i = 0; i < n; i++) {
                    System.out.println("Enter the Price of Movie , Number of Tickets , Name of Movie ");
                    String name;
                    int price;
                    int ticket;

                    price = Sc.nextInt();
                    ticket = Sc.nextInt();
                    name = Sc.nextLine();

                    Updatedata UD = new Updatedata(name, ticket, price);
                }


//                 for booking the ticket
            } else if (cnd == 2) {

                System.out.println("Enter the Number of Tickets you want to book and Name of Movie");
                String s;
                int t;
                t = Sc.nextInt();
                s = Sc.nextLine();
                Updatedata UD = new Updatedata();
                if (UD.mpprice.containsKey(s)) {

                    Bookedticket b1 = new Bookedticket();

                    b1.bookticket(s, t);
                } else {
                    System.out.println("Sorry this Movie is not available ");
                }


//                 for increasing the number of ticket already present
            } else if (cnd == 3) {

                String name;
                int ticket;
                System.out.println("ENter the number  of Ticket and name of  Movie ");
                ticket = Sc.nextInt();
                name = Sc.nextLine();
                Updatedata UD = new Updatedata();
                try {

                    int ttt = UD.mpprice.get(name);
                    Updatedata UDT = new Updatedata(name, ticket);
                } catch (Exception e) {
                    System.out.println("Sorry we cannot update , this movie does't exist");
                    System.out.println(e);
                }


//                 for displaying the data of already  present movies
            } else if (cnd == 4) {
                displaybookeddata d1 = new displaybookeddata();
                d1.display();


            }
            System.out.println("WELCOME TO BOOK MY SHOW ");
            System.out.println("FOR UPDATING THE DATA OF MOVIES PRESS 1");
            System.out.println("FOR BOOKING THE TICKET PRESS 2");
            System.out.println("FOR INCREASING THE NUMBER OF TICKETS OF ALREADY PRESENT MOVIES PRESS 3");
            System.out.println("FOR DISPLAYING DATA OF BOOKED MOVES PRESS 4");
            System.out.print("FOR EXIT ENTER ANY NUMBER EXCEPT 1,2,3 AND 4");
            cnd = Sc.nextInt();
        }
    }


}
