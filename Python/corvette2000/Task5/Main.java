import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class Main {
        public static void printInfo(ArrayList<Plant> myGarden){
            for (Plant plant:myGarden) {
                plant.printInfo();
                System.out.println();
            }

        }
    public static void main(String[] args) {
        ArrayList<Plant> myGarden = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {

            String input = scanner.nextLine().strip();
            if (Objects.equals(input, "-1"))
                break;

            String[] input_data = input.split(" ");

            if (Objects.equals(input_data[0], "plant")) {
                Plant plant = new Plant();
                plant.setPlantName(input_data[1]);
                plant.setPlantCost(input_data[2]);

                myGarden.add(plant);
            }
            else if (Objects.equals(input_data[0], "flower")) {
                Flower flower = new Flower();
                flower.setPlantName(input_data[1]);
                flower.setPlantCost(input_data[2]);

                flower.setPlantType(Objects.equals(input_data[3], "true"));
                flower.setColorOfFlowers(input_data[4]);

                myGarden.add(flower);
            }

        }
        printInfo(myGarden);


    }
}
