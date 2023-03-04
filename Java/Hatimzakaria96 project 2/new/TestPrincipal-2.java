public class TestPrincipal {
    public static void main(String args[]){
        
        System.out.println("////////////////////////////////////////////////////////////////////////////////////////////////////");
        System.out.println("Batch de test #0 \n");
        


        SavaneTest savane = new SavaneTest(8,1.0,500,1.0,101,20000,200000,3.0,true);
        
        double[] testing = savane.simule();
        if(testing[0]-1<1){
            print("Note actuel 0/5");
        }
        else if(testing[0]-1<2){
            print("Note actuel 2/5");
        }
        else if(testing[0]-1<11){
            print("Note actuel 3/5");
        }
        else if(testing[0]-1<100){
            print("Note actuel 4/5");
        }
        else {
            print("Note actuel 5/5");
        }        
    }
    public static void print( String text){
        System.out.println(text);
    }
    public static void print( int text){
        System.out.println(text);
    }
    public static void print( double text){
        System.out.println(text);
    }
}
