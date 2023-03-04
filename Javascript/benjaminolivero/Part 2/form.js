// Person class
class Person {
    // Constructor
    constructor(name, age) {
        this.name = name;
        this.age = parseInt(age);
        // Set legal or not according to the age
        this.legal = age >= 18 ? "Legal Age" : "Not Legal Age";
    }

    // toString method
    toString() {
        return this.name + ", " + this.age + ", " + this.legal + "<br>";
    }

    // birthday method
    birthday() {
        // Increment age by 1
        this.age += 1;

        //  Update validity if age is greater than 17
        if(this.age >= 18)
            this.legal = "Legal Age";
    }

    // greeting method
    greeting(otherPerson) {
        // greet to given person
        return "Hello " + otherPerson.name + ". My name is " + this.name + "<br>";
    }
}

// Array to hold the Person objects
let persons = [];

function onSubmit() {

    // Get user input values for name, age and password
    let name = document.getElementById("name").value
    let age = document.getElementById("age").value
    let password = document.getElementById("password").value

    // Initially set error text as empty for each field
    let name_error_text = "";
    let age_error_text = "";
    let password_error_text = "";

    // Check the validity of name
    if (name.length === 0) {
        name_error_text = "Invalid Name";
    }

    // Check the validity of age
    if (age.length === 0) {
        age_error_text = "Invalid Age";
    }

    // Check the validity of the password
    if (password !== "IHM") {
        password_error_text = "Invalid Password";
    }

    // Display error texts for each field
    document.getElementById("name_error").innerHTML = name_error_text;
    document.getElementById("age_error").innerHTML = age_error_text;
    document.getElementById("password_error").innerHTML = password_error_text;


    // If there is no error (All the field are valid)
    if ((name_error_text.length === 0) && (age_error_text.length === 0) && (password_error_text.length === 0)) {
        // Create Person object with given name and age
        let person = new Person(name, age);
        // add person to persons Array
        persons.push(person);

        // generate details using toString method
        let details = "";
        for (let i = 0; i < persons.length; i++) {
            details += persons[i].toString();
        }

        // show details
        document.getElementById("details").innerHTML = details;

    }
}

// birthday function
function birthday(){
    let details = "";

    // Iterate through each person object and increment birthday by 1
    for (let i = 0; i < persons.length; i++) {
        persons[i].birthday();
        details += persons[i].toString();
    }

    // show details
    document.getElementById("details").innerHTML = details;
}


// greetAll function
function greetAll(){
    let greet = "";
    // Iterate through each person object
    for (let i = 0; i < persons.length; i++) {
        // Iterate again through each person object
        for (let j = 0; j < persons.length; j++) {

            // Avoid greeting to himself
            if(i === j)
                continue;

            // call greeting method
            greet += persons[i].greeting(persons[j]);
        }
        greet += "<br>";
    }

    // show greeting messages
    document.getElementById("greet").innerHTML = greet;
}