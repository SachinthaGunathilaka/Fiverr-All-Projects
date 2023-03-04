let badge_count = 0
let badges = [0, 0, 0];
let badges_prices = [7.50, 8.00, 10.00];
let paymentMethod = "cheque";



function onClickPaymentMethod(method) {
    let card_element = document.getElementById("credit_card_details");
    paymentMethod = method.value;

    if (paymentMethod === "creditcard") {
        card_element.innerHTML = "<h5 style=\"width: 200px; margin-bottom: 10px\">CHARGE MY: </h5>\n" +
            "\n" +
            "                <div class=\"radio\">\n" +
            "                    <input type=\"radio\" id=\"visa\" name=\"Paymenttype\" value=\"visa\">\n" +
            "                    <label for=\"visa\">Visa</label><br>\n" +
            "                </div>\n" +
            "                <div class=\"radio\">\n" +
            "                    <input type=\"radio\" id=\"mc\" name=\"Paymenttype\" value=\"mastercard\">\n" +
            "                    <label for=\"mc\">Master Card</label><br>\n" +
            "                </div>\n" +
            "\n" +
            "                <div class=\"row\">\n" +
            "                    <div class=\"col\">\n" +
            "                        <label class=\"last_col2\" for=\"crdname\">Name On Card</label>\n" +
            "                        <input type=\"text\" required placeholder=\"Anastasia\" name=\"crdname\" id=\"crdname\">\n" +
            "                        <div id=\"crdname_err\" class=\"err\"></div>\n" +
            "\n" +
            "                    </div>\n" +
            "                </div>\n" +
            "\n" +
            "                <div class=\"row\">\n" +
            "                    <div class=\"col\">\n" +
            "                        <label class=\"last_col2\" for=\"ccnum\">Credit Card Number</label>\n" +
            "                        <input type=\"text\" required placeholder=\"****************\" name=\"ccnum\" id=\"ccnum\">\n" +
            "                        <div id=\"ccnum_err\" class=\"err\"></div>\n" +
            "\n" +
            "                    </div>\n" +
            "                </div>\n" +
            "\n" +
            "                <div class=\"row\">\n" +
            "                    <div class=\"col\">\n" +
            "                        <label class=\"last_col2\" for=\"cvvno\">CVV No.</label>\n" +
            "                        <input type=\"text\" required placeholder=\"***\" name=\"cvvno\" id=\"cvvno\">\n" +
            "                        <div id=\"cvvno_err\" class=\"err\"></div>\n" +
            "\n" +
            "                    </div>\n" +
            "                </div>\n" +
            "\n" +
            "\n" +
            "                <div class=\"row\">\n" +
            "                    <label class=\"last_col2\" for=\"mnthexp\">Expiry Month</label>\n" +
            "                    <select id=\"mnthexp\">\n" +
            "                        <option label=\"January\">1</option>\n" +
            "                        <option label=\"February\">2</option>\n" +
            "                        <option label=\"March\">3</option>\n" +
            "                        <option label=\"April\">4</option>\n" +
            "                        <option label=\"May\">5</option>\n" +
            "                        <option label=\"June\">6</option>\n" +
            "                        <option label=\"July\">7</option>\n" +
            "                        <option label=\"August\">8</option>\n" +
            "                        <option label=\"September\">9</option>\n" +
            "                        <option label=\"October\">10</option>\n" +
            "                        <option label=\"November\">11</option>\n" +
            "                        <option label=\"December\">12</option>\n" +
            "                    </select>\n" +
            "                    <div id=\"mnthexp_err\" class=\"err\"></div>\n" +
            "                </div>\n" +
            "\n" +
            "\n" +
            "                <div class=\"row\">\n" +
            "\n" +
            "                    <label class=\"last_col2\" for=\"yrexp\">Expiry Year</label>\n" +
            "                    <select id=\"yrexp\">\n" +
            "                        <option label=\"2021\">2021</option>\n" +
            "                        <option label=\"2022\">2022</option>\n" +
            "                        <option label=\"2023\">2023</option>\n" +
            "                        <option label=\"2024\">2024</option>\n" +
            "                        <option label=\"2025\">2025</option>\n" +
            "                    </select>\n" +
            "                    <div id=\"yrexp_err\" class=\"err\"></div>\n" +
            "                </div>\n" +
            "\n" +
            "                <div id=\"expire_err\" class=\"err\"></div>\n" +
            "\n"

        // card_element.style.display = "block";
        // card_element.style["pointer-events"] = "auto";

    } else {
        // card_element.style.display = "none";
        // card_element.style.visibility = 'hidden';      // Hide

        // card_element.style["pointer-events"] = "none";

        card_element.innerHTML = "";



    }
}


function validateDateOrder(date) {

    if (isEmpty(date))
        return false;

    let date_now = new Date();

    let date_order = new Date(date + " 0:00:00");

    if (date_now < date_order) {
        return false;
    }
    return true;
}

function isEmpty(data) {
    return data.trim().length === 0;
}

function validateClubNumber(data) {
    const pattern = /^[cC][a-zA-Z0-9]{2}-[a-zA-Z0-9]{3}$/;
    return pattern.test(data);
}

function validateTelNumber(data) {
    const pattern = /^[0-9]{10}$/;
    return pattern.test(data);
}

function validatePostCode(data) {
    const pattern = /^[0-9]{4}$/;
    return pattern.test(data);
}

function validateName(data) {
    const pattern = /^[a-zA-Z -]+$/;
    return pattern.test(data);
}

function validateBadges() {

    let fname1 = document.getElementById("fname1").value;
    let surname1 = document.getElementById("surname1").value;
    let bdgoption1 = document.getElementById("bdgoption1").value;

    let fname2 = document.getElementById("fname2").value;
    let surname2 = document.getElementById("surname2").value;
    let bdgoption2 = document.getElementById("bdgoption2").value;

    let fname3 = document.getElementById("fname3").value;
    let surname3 = document.getElementById("surname3").value;
    let bdgoption3 = document.getElementById("bdgoption3").value;

    let fname4 = document.getElementById("fname4").value;
    let surname4 = document.getElementById("surname4").value;
    let bdgoption4 = document.getElementById("bdgoption4").value;

    let fname5 = document.getElementById("fname5").value;
    let surname5 = document.getElementById("surname5").value;
    let bdgoption5 = document.getElementById("bdgoption5").value;

    badge_count = 0
    badges = [0, 0, 0]
    if (validateName(fname1) && validateName(surname1)) {
        badges[bdgoption1]++;
        badge_count++;
    }
    if (validateName(fname2) && validateName(surname2)) {
        badges[bdgoption2]++;
        badge_count++;
    }
    if (validateName(fname3) && validateName(surname3)) {
        badges[bdgoption3]++;
        badge_count++;
    }
    if (validateName(fname4) && validateName(surname4)) {
        badges[bdgoption4]++;
        badge_count++;
    }

    if (validateName(fname5) && validateName(surname5)) {
        badges[bdgoption5]++;
        badge_count++;
    }

    return badge_count !== 0;


}

function validateCardNumber(data) {
    if (paymentMethod !== "creditcard")
        return true
    const pattern = /^[0-9]{16}$/;
    return pattern.test(data);
}

function validateCVV(data) {
    if (paymentMethod !== "creditcard")
        return true
    const pattern = /^[0-9]{3}$/;
    return pattern.test(data);
}

function isOnlyChar(data) {
    if (paymentMethod !== "creditcard")
        return true

    const pattern = /^[a-zA-Z]+$/;
    return pattern.test(data);
}

function validateExpireDate(year, month) {
    if (paymentMethod !== "creditcard")
        return true

    let date_now = new Date();

    if (parseInt(year) > date_now.getFullYear()) {
        return true;
    } else if ((parseInt(year) === date_now.getFullYear()) && (parseInt(month) > (date_now.getMonth() + 1))) {
        return true;
    }
    return false;

}


function validateForm() {
    document.forms["post-form"]
    let isFormValid = true;

    let date = document.forms["post-form"]["date"].value;
    let clbname = document.forms["post-form"]["clbname"].value;
    let clbnumber = document.forms["post-form"]["clbnumber"].value;
    let pnum = document.forms["post-form"]["pnum"].value;
    let fname = document.forms["post-form"]["fname"].value;
    let lname = document.forms["post-form"]["lname"].value;

    let address = document.forms["post-form"]["address"].value;
    let city = document.forms["post-form"]["city"].value;
    let pstcode = document.forms["post-form"]["pstcode"].value;

    let ccnum = "", crdname = "", cvvno = "", mnthexp = "", yrexp = "";

    if (paymentMethod === "creditcard") {
        ccnum = document.forms["post-form"]["ccnum"].value;
        console.log(ccnum)

        crdname = document.forms["post-form"]["crdname"].value;
        console.log(crdname)
        cvvno = document.forms["post-form"]["cvvno"].value;
        mnthexp = document.forms["post-form"]["mnthexp"].value;
        yrexp = document.forms["post-form"]["yrexp"].value;
    }


    document.getElementById("date_err").innerText = !validateDateOrder(date) ? "Invalid date" : "";
    document.getElementById("clbname_err").innerText = isEmpty(clbname) ? "Club name cannot be empty" : "";
    document.getElementById("clbnumber_err").innerText = !validateClubNumber(clbnumber) ? "Invalid club number" : "";
    document.getElementById("pnum_err").innerText = !validateTelNumber(pnum) ? "Invalid contact number" : "";
    document.getElementById("fname_err").innerText = !validateName(fname) ? "Invalid first name" : "";
    document.getElementById("lname_err").innerText = !validateName(lname) ? "Invalid last name" : "";
    document.getElementById("address_err").innerText = isEmpty(address) ? "Address cannot be empty" : "";
    document.getElementById("city_err").innerText = isEmpty(city) ? "City cannot be empty" : "";
    document.getElementById("pstcode_err").innerText = !validatePostCode(pstcode) ? "Invalid post code" : ""

    document.getElementById("badge_err").innerText = !validateBadges() ? "Badges details should be completed and there must be at least 1 badge." : "";

    if (paymentMethod === "creditcard") {
        document.getElementById("ccnum_err").innerText = !validateCardNumber(ccnum) ? "Invalid credit card number" : ""
        document.getElementById("crdname_err").innerText = !isOnlyChar(crdname) ? "Invalid name" : ""
        document.getElementById("cvvno_err").innerText = !validateCVV(cvvno) ? "Invalid cvv" : ""
        document.getElementById("expire_err").innerText = !validateExpireDate(yrexp, mnthexp) ? "Invalid expire year and month" : ""
    }


    if (!validateDateOrder(date) || isEmpty(clbname) || !validateClubNumber(clbnumber) || !validateTelNumber(pnum) || !validateName(fname)
        || !validateName(lname) || isEmpty(address) || isEmpty(city) || !validatePostCode(pstcode) || !validateBadges() || !validateCardNumber(ccnum)
        || !isOnlyChar(crdname) || !validateCVV(cvvno) || !validateExpireDate(yrexp, mnthexp)) {
        isFormValid = false;
    }

    if (isFormValid) {
        document.getElementById("badgeoption1").innerText = "$ " + badges_prices[0].toFixed(2) + "\u00A0\u00A0\u00A0\u00A0@\u00A0\u00A0\u00A0\u00A0" + badges[0] + "\u00A0\u00A0\u00A0\u00A0\u00A0\u00A0=>\u00A0\u00A0$ " + (badges_prices[0] * badges[0]).toFixed(2);
        document.getElementById("badgeoption2").innerText = "$ " + badges_prices[1].toFixed(2) + "\u00A0\u00A0\u00A0\u00A0@\u00A0\u00A0\u00A0\u00A0" + badges[1] + "\u00A0\u00A0\u00A0\u00A0\u00A0\u00A0=>\u00A0\u00A0$ " + (badges_prices[1] * badges[1]).toFixed(2);
        document.getElementById("badgeoption3").innerText = "$ " + badges_prices[2].toFixed(2) + "\u00A0\u00A0@\u00A0\u00A0\u00A0\u00A0" + badges[2] + "\u00A0\u00A0\u00A0\u00A0\u00A0\u00A0=>\u00A0\u00A0$ " + (badges_prices[2] * badges[2]).toFixed(2);

        let postal_cost = badge_count < 5 ? 4 : 8;

        let total = postal_cost;
        for (let i = 0; i < 3; i++) {
            total += badges[i] * badges_prices[i];
        }
        document.getElementById("postal_cost").innerText = "$ " + postal_cost.toFixed(2);
        document.getElementById("Sub_total").innerText = "$ " + total.toFixed(2).toString();


        let card_fee = 0;
        if (paymentMethod === "creditcard") {
            card_fee = total * 2.5 / 100;
        }
        document.getElementById("credit_card_fee").innerText = "$ " + card_fee.toFixed(2).toString();
        document.getElementById("total").innerText = "$ " + (total - card_fee).toFixed(2).toString();

        document.getElementById('post-form').action = "https://twasum.cdms.westernsydney.edu.au/twainfo/echo.php"; //Will set it

    }

    else{
        document.getElementById("post-form").addEventListener("click", function(event){
            event.preventDefault()
        });
    }

}