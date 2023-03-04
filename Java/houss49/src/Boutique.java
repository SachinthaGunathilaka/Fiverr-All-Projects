public class Boutique {
    private String code;
    private String name;
    private String domain;
    private double area;
    private int decor_type_elements;
    private int num_of_employees;
    private Person[] employees;
    private int num_of_objects;
    private Object[] objects;

    public Boutique() {
        num_of_objects = 0;
        num_of_employees = 0;
    }

    public String displayInventory() {
        String result = "Store name : " + name + "\n";
        for (int i = 0; i < num_of_objects; i++) {
            result += objects[i].getCode() + " : " + objects[i].getTotal_quantity();
        }
        return result;
    }

    public void hirePerson(Person p) {
        employees[num_of_employees++] = p;
    }

    public void firePerson(Person p) {
        int i;
        for (i = 0; i < num_of_employees; i++) {
            if (employees[i].getName().equalsIgnoreCase(p.getName())) {
                break;
            }
        }
        if(i == num_of_employees){
            System.out.println("Employee not found");
        }
        else{
            for (int j = i; j < num_of_employees-1; j++) {
                employees[j] = employees[j+1];
            }
            employees[num_of_employees-1] = null;
        }

    }

}
