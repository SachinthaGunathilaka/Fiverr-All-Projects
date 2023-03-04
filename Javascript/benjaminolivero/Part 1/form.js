function onSubmit() {

    // Arrays to hold the names and ages
    let names = []
    let ages = []

    // Get user input valus for name, age and password
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
    if(password !== "IHM"){
        password_error_text = "Invalid Password";
    }

    // Display error texts for each field
    document.getElementById("name_error").innerHTML =  name_error_text;
    document.getElementById("age_error").innerHTML =  age_error_text;
    document.getElementById("password_error").innerHTML =  password_error_text;

    // If there is no error (All the field are valid)
    if((name_error_text.length === 0) && (age_error_text.length === 0) && (password_error_text.length === 0)){
        // Add input name to the names Array
        names.push(name);
        // Add 2 more names to the names Array
        names.push("Marcus");
        names.push("Cihan");

        // Add input age to the names Array
        ages.push(age);
        // Add 2 more ages to the ages Array
        ages.push(12);
        ages.push(21);
    }

    let greeting_message = ""
    // generate greeting message by iterating through the names Array
    names.forEach(name =>{
        greeting_message += "Hello " + name + "<br>";
    })

    // Show greeting message
    document.getElementById("greet").innerHTML = greeting_message;

    let details = "";
    // generate details by iterating through the names and ages Array
    for (let i = 0; i < names.length; i++) {
        details += names[i] + ", " + ages[i] + ", ";
        details += ages[i] >= 18 ? "Legal Age" : "Not Legal Age" ; // set whether the age is legal or not
        details += "<br>";
    }

    // Show details
    document.getElementById("details").innerHTML = details;











}