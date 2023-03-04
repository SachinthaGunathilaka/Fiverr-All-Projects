
import java.util.Scanner;  // Import the Scanner class
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.FileWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.StringTokenizer;
import java.io.*;

public class Akbar_Park {

    
    public static void main(String[] args) {
        
        
        Scanner myObj = new Scanner(System.in);  // Create a Scanner object
        
        System.out.println("Welcome");
        System.out.println("************************************");
        System.out.println("********Welcome to Akbar Park*******");
        System.out.println("************************************");
        
        
        String[][] ticket_list= {{"1", "11AM-1PM", "13.99", "4/4/2022"},{"2", "1PM-3PM", "13.99", "4/4/2022"},{"3", "3PM-5PM","18.99", "4/4/2022"},{"4", "5PM-7PM", "18.99", "4/4/2022"},{"5", "11AM-1PM", "13.99", "4/5/2022"},{"6", "1PM-3PM", "13.99", "4/5/2022"},{"7", "3PM-5PM", "18.99", "4/5/2022"},{"8", "5PM-7PM", "18.99", "4/5/2022"}};
        
        String person_type = "";
        int ticket_count = 0;
        double balance = 0;
        int ticket_no = 0;
        
         
        
        while(true){
            
            System.out.println("Already signed up? [y/n] :");
            char answer = myObj.next().charAt(0);   
            
            if(answer == 'y')
            {
                System.out.println("*******Sign In*******");
                log_in();
                break;
            }
            else if(answer == 'n')
            {
                System.out.println("*******Sign Up*******");
                sign_up();
                break;
            }
            else
            {
                System.out.println("Please enter y or n!");
            }
        }
        while(true)
        {
            System.out.println("Choose an item [1-7].\n1- Buy a Ticket\n2- Reserve a Ride\n3- Buy Food\n4- Show the Orders\n5- Check Out\n6- Clear the Cart\n7- Exit\n");
            int answer = myObj.nextInt();
            
            double discount = 0;
            int ride_fee = 0;
            double food_fee = 0;
            BufferedReader reader1;
            if(answer == 1)
            {
                try {
                    File reader = new File("tickets.txt");
                    Scanner myReader = new Scanner(reader);
                    while (myReader.hasNextLine()) {
                      String data = myReader.nextLine();
                      System.out.println(data);
                    }
                    myReader.close();
                    
                    Scanner myObj4 = new Scanner(System.in);  // Create a Scanner object
                    System.out.println("Select a Ticket from a list [1-8]");
                    ticket_no = myObj4.nextInt();
                    System.out.println("Are you a student(s), an adult(a) ora kid(k)? [s/a/k]:");
                    myObj4.nextLine();
                    person_type = myObj4.nextLine();
                    System.out.println("How many tickets do you want?");
                    ticket_count = myObj4.nextInt();
                   
                    double ticket_price = Double.parseDouble(ticket_list[ticket_no-1][2]) * Double.valueOf(ticket_count);
                    
                    if(null != person_type)
                    switch (person_type) {
                        case "s":
                            discount = ((Double.parseDouble(ticket_list[ticket_no - 1][2]) * 8) / 100) * Double.valueOf(ticket_count);
                            break;
                        case "a":
                            discount = 0;
                            break;
                        case "k":
                            discount = ((Double.parseDouble(ticket_list[ticket_no - 1][2]) * 9) / 100) * Double.valueOf(ticket_count);
                            break;
                        default:
                            break;
                    }
                    
                    double ticket_charge = ticket_price - discount;
                    balance += ticket_charge;
                    System.out.println("The tickets have been added to your cart, your balance is $"+ balance);
                    
                    String add_ticket = ticket_list[ticket_no - 1][1]+","+"$"+ticket_charge+","+ticket_list[ticket_no - 1][3];
                    
                    try 
                    {
           
                        FileWriter fw=new FileWriter("cart.txt", true);
                        reader1 = new BufferedReader(new FileReader("cart.txt"));

                        if(reader1.readLine() == null)
                        {
                            fw.write(add_ticket); 
                            

                        }
                        else
                        {
                            fw.write("\n"+add_ticket);
                            
                        }

                        fw.close(); 
                        reader1.close();
                    } 
                    catch (IOException e) 
                    {
                        e.printStackTrace();
                    }
                    
                  } catch (FileNotFoundException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                  }
            }
            else if(answer == 2)
            {
                if(ticket_count == 0)
                {
                    System.out.println("Please buy at least one ticket!");
                }
                else
                {
                    String name = "";
                    if(null != person_type)
                    switch (person_type) {
                        case "s":
                            ride_fee = 20 * ticket_count;
                            name = "student";
                            break;
                        case "a":
                            ride_fee = 30 * ticket_count;
                            name = "adult";
                            break;
                        case "k":
                            ride_fee = 0;
                            name = "kid";
                            break;
                        default:
                            break;
                    }
                    balance += ride_fee;
                    System.out.println("Your ride cost is $" +ride_fee+ "per " + name +",for "+ticket_list[ticket_no - 1][1]);
                    System.out.println("The tickets have been added to your cart, your balance is $"+ balance);
                    String add_ride = "A ride is reserved $"+ride_fee;
                    try 
                    {
           
                        FileWriter fw=new FileWriter("cart.txt", true);
                        reader1 = new BufferedReader(new FileReader("cart.txt"));

                        if(reader1.readLine() == null)
                        {
                            fw.write(add_ride); 
                            

                        }
                        else
                        {
                            fw.write("\n"+add_ride);
                            
                        }

                        fw.close(); 
                        reader1.close();
                    } 
                    catch (IOException e) 
                    {
                        e.printStackTrace();
                    }
                }
                
            }
            else if(answer == 3)
            {
                if(ticket_count == 0)
                {
                    System.out.println("Please buy at least one ticket!");
                }
                else
                {
                    try {
                    File reader = new File("Foodmenu.txt");
                    Scanner myReader = new Scanner(reader);
                    while (myReader.hasNextLine()) {
                      String data = myReader.nextLine();
                      System.out.println(data);
                    }
                    myReader.close();
                    
                    Scanner myObj5 = new Scanner(System.in);  // Create a Scanner object
                    System.out.println("What do you want to order? (type the menu item)");
                    String food_request = myObj5.nextLine();
                    System.out.println(food_request);
                    food_fee = 0;
                            
                    if( null == food_request)
                    {
                        System.out.println("Please enter valid food!");
                    }
                    else switch (food_request) {
                            case "Taco":
                                food_fee = 3.99;
                                break;
                            case "Burritos":
                                food_fee = 7.99;
                                break;
                            case "Nachos":
                                food_fee = 2.99;
                                break;
                            case "Quesadilla":
                                food_fee = 11.99;
                                break;
                            case "Burger":
                                food_fee = 5.99;
                                break;
                            case "Cheeseburger":
                                food_fee = 6.99;
                                break;
                            default:
                            System.out.println("Please enter valid food!");
                                break;
                        }
                    
                    balance += food_fee;
                    System.out.println("A " + food_request + " is added to your order");
                    System.out.println("Your balance is $" + balance);
                    
                    String add_food = food_request + food_fee;
                    
                    
                    try 
                    {
           
                        FileWriter fw=new FileWriter("cart.txt", true);
                        reader1 = new BufferedReader(new FileReader("cart.txt"));

                        if(reader1.readLine() == null)
                        {
                            fw.write(add_food); 
                            

                        }
                        else
                        {
                            fw.write("\n"+add_food);
                            
                        }

                        fw.close(); 
                        reader1.close();
                    } 
                    catch (IOException e) 
                    {
                        e.printStackTrace();
                    }
                    
                  } catch (FileNotFoundException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                  }
                }
            }
            else if(answer == 4)
            {
                try {
                    File reader = new File("cart.txt");
                    Scanner myReader = new Scanner(reader);
                    while (myReader.hasNextLine()) {
                      String data = myReader.nextLine();
                      System.out.println(data);
                    }
                    myReader.close();
                
                } 
                catch (FileNotFoundException e) 
                {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
            }
            else if(answer == 5)
            {
                double tax_rate = 0;
                double total_cost = 0;
                BufferedReader file;
                try {
                    File reader = new File("cart.txt");
                    try (Scanner myReader = new Scanner(reader)) {
                        while (myReader.hasNextLine()) {
                            String data = myReader.nextLine();
                            System.out.println(data);
                        }
                    }
                    System.out.println("Your total cost before TAX is $"+balance);
                    Scanner myObj6 = new Scanner(System.in);  // Create a Scanner object
                    System.out.println("Please enter your State [Texas, New-York, ....]");
                    String state = myObj6.nextLine();
                    try {
                        file = new BufferedReader(new FileReader("StateTaxRate.txt"));
                        String line = file.readLine();
                        while (line != null) {
                                StringTokenizer stn = new StringTokenizer(line);
                                String State_file = stn.nextToken();
                                if(state.equals(State_file))
                                {
                                    tax_rate = Double.valueOf(stn.nextToken());
                                    break;
                                }                               
                        }
                        total_cost = (balance * (100 + tax_rate)) / 100;
                        System.out.println("Your Tax rate is " + tax_rate);
                        System.out.println("Your total cost after TAX is $" + total_cost);
                        System.out.println("Please enter your card number (16 digits)");
                        int card_no = myObj6.nextInt();
                        if(Character.isDigit(card_no))
                        {
                            System.out.println("The transaction has been approved! Thank you.");
                        }
                        else
                        {
                            System.out.println("Please enter valid credit card number!");
                        }
                        myObj6.close();  
                        file.close();    


                    } catch (IOException e) {
                            e.printStackTrace();
                    }
                
                } 
                catch (FileNotFoundException e) 
                {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
            }
            else if(answer == 6)
            {
                try{
                    System.out.println("Are you sure? [y/n] :");
                    char sure = myObj.next().charAt(0);   
            
                    switch (sure) {
                        case 'y':
                            FileWriter fw = new FileWriter("cart.txt", false);
                            PrintWriter pw = new PrintWriter(fw, false);
                            pw.flush();
                            pw.close();
                            fw.close();
                            System.out.println("Items from the cart have been removed!");
                            break;
                        case 'n':
                            continue;
                        default:
                            System.out.println("Please enter y or n!");
                            break;
                    }
                }catch(Exception exception){

                    System.out.println("Exception have been caught");

                }
            }
            else if(answer == 7)
            {
                System.out.println("Have a great day!, See you soon!");
                System.exit(0);
            }
            else
            {
                System.out.println("Please enter number between 1 and 7!");
            }
            
        }
        
        
    }
    
    
    private static void sign_up()
    {
        String[] save_data;
        String data = "";
        String correct_email = "";
        String correct_password = "";
        BufferedReader reader;
        Scanner myObj2 = new Scanner(System.in);  // Create a Scanner object
        int count_email = 0;
        int count_password = 0;
        
        while(count_email<3)
        {
            System.out.println("Enter your email address: ");
            String email =  myObj2.nextLine();
            if(isValidEmail(email))
            {
                correct_email = email;
                break;
            }
            else
            {
                System.out.println("incorrect email address");
                count_email++;
            }
        }
        while(count_password<3)
        {
            System.out.println("Enter your password: (At least 8 characters, uppercase and lowercase, and one digit and one special character)");
            String password =  myObj2.nextLine();

            if(isValidPassword(password))
            {
                correct_password = password;
                break;
            }
            else
            {
                System.out.println("incorrect password ");
                count_password++;
            }
        
        }
        
        
        data = correct_email +","+ correct_password;
        
        
        try {
           
           FileWriter fw=new FileWriter("authenticateFile.txt", true);
           reader = new BufferedReader(new FileReader("authenticateFile.txt"));
           
           if(reader.readLine() == null)
           {
               fw.write(data); 
               System.out.println("Sign Up Successful!");
               
           }
           else
           {
               fw.write("\n"+data);
               System.out.println("Sign Up Successful!");
           }
               
           fw.close(); 
           reader.close();
        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
        
    }
    public static boolean isValidPassword(String password)
    {
        String regex = "^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{8,20}$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(password);
        return matcher.matches();
    }
    public static boolean isValidEmail(String email) 
    { 
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@" +  //part before @
                "(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$"; 
 
        Pattern pat = Pattern.compile(emailRegex); 
        if (email == null) 
            return false; 
        return pat.matcher(email).matches(); 
    } 
    
    private static void log_in()
    {
        Scanner myObj1 = new Scanner(System.in); 
        int count =0;
        boolean user_login = false;
        // list that holds strings of a file
        List<String> Student_list = new ArrayList<String>();
        BufferedReader reader;
        try {
                reader = new BufferedReader(new FileReader("authenticateFile.txt"));
                String line = reader.readLine();
                while (line != null) {
                        Student_list.add(line);
                        // read next line
                        line = reader.readLine();
                }
                reader.close();
                // storing the data in arraylist to array
                String[] array = Student_list.toArray(new String[0]);
                
                while(count<3)
                {
                    System.out.println("Enter your email address: ");
                    String email =  myObj1.nextLine();
                    System.out.println("Enter your Password: ");
                    String password =  myObj1.nextLine();

                    for(int i =0;i<array.length;i++)
                    {
                        if(email.equals(array[i].split(",")[0]) && password.equals(array[i].split(",")[1]))
                        {
                            user_login = true;
                            break;
                        } 
                    }
                    if(user_login == true)
                    {
                        System.out.println("Sign In Successful!");
                        break;
                    }
                    else
                    {
                        System.out.println("Wrong email or password!");
                        count+=1;
                        if(count == 3)
                        {
                            System.exit(0);
                        }
                    }
                }
                
                //System.out.println(array.length);
                //System.out.println(array[0].split(",")[0]);
                
        } catch (IOException e) {
                e.printStackTrace();
        }
    }
    
    
}
