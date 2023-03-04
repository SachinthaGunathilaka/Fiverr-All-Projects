// Purpose
// A program to demonstrate an the operation of a simple room controller, the 
// sensors attached to the controller are simulated, so are setup and updated by 
// the user with keyboard input. After each change, or menu update the controller 
// checks if it needs to turn on the heating to control temperature, or a
// humidifier to increase humidty. It does this by reading the average temperature
// or humidty across all sensors added to the system and if the average is less
// than the target, heating/humidifier should be turned on.

// Background
// Home/Office Automation Controllers often deal with a number of types of sensors,
// and often make decisions based on the average input of multiple sensors.

// Limitations
// For the purposes of the simulation, all inputs do not contain spaces.
// No testing or validation is made on the values given to the sensors.

#include <iostream>
#include <cstdint>
using namespace std;

// For the purposes of the simulation, we define a maximum number of sensors that
// can be added to the system and we check if we pass this limit when we try to add
// more.
#define MAX_NUM_SENSORS 5
enum { INVALID, TEMPERATURE, HUMIDTY };

// The 'Sensors' structure describes a single sensor, it's type and current value.
//   type - describes the type of sensor 0 (INVALID), 1 (TEMPERATURE), 2 (HUMIDITY)
//   value - the current value of the sensor.
//   valid - set to TRUE if the sensor is valid, should default to FALSE until set up.
struct Sensors {
    uint16_t type;
    float    value;
    bool     valid;
};

// The 'RoomControllers' structure describes the main room controller.
//   sensor - An array of sensors of the Sensors structure define above.
//   targetTemperature - The set target temperature in degrees C, defaults to 19.0
//   currentlyHeating - TRUE if controller has enabled heating.
//   targetHumidity - The set target humidity, defaults to 50%
//   currentlyHumidifying - TRUE if controller has enabled the humidifier.
struct RoomControllers {
    Sensors sensor[MAX_NUM_SENSORS];
    float   targetTemperature;
    bool    currentlyHeating;
    float   targetHumidity;
    bool    currentlyHumidifying;
};

// Prototype - Print the state of each sensor and the controller settings.
void printStates(const Sensors[], const float&, const bool&, const float&, const bool&);

// Prototype - Allow the user to define a new sensor with a default value.
uint8_t newSensor(Sensors[]);
enum { NEW_SENSOR, SENSOR_NOT_VALID, MAX_SENSORS_REACHED };

// Prototype - Update the value of a previously defined sensor.
uint8_t updateSensor(Sensors[]);
enum { OK, INVALID_SENSOR_SELECTED };

// Prototypes - Allow the user to define the target temperature or humidity.
void setTemperatureTarget(float&);
void setHumidityTarget(float&);

// Prototype - Called at the end of any option given, check if heating or 
//             humidifier needs to be turned on or off.
uint8_t checkValues(const Sensors[], const float&, bool&, const float&, bool&);
enum { NO_CHANGE, HEATING_STATUS_CHANGED, HUMIDIFIER_STATUS_CHANGED };


// Control and view the state of a room using a controller.
// Arguments - none
// Returns: 0 - On completion
int main() {

    RoomControllers roomController = { {0},19.0,false,50.0,false };

    // Holds the menu choice entered by the user.
    char userInput;

    // Loop until the user chooses the exit option.
    while (1) {

        // Show the menu options.
        cout << endl;
        cout << "----------------------------" << endl;
        cout << "Room Control Simulation Menu" << endl;
        cout << "----------------------------" << endl;
        cout << "1. View the state of the Room" << endl;
        cout << "2. Add a new sensor" << endl;
        cout << "3. Change the value of a sensor" << endl;
        cout << "4. Set a target temperature" << endl;
        cout << "5. Set a target humidity" << endl;
        cout << "6. Exit the program" << endl << endl;

        // Get the user's choice
        cout << "Enter your option [1-6]: "; cin >> userInput;
        cout << endl;

        // Act on the input, choosing a different function.
        switch (userInput) {
        case '1':
            printStates(roomController.sensor,
                roomController.targetTemperature, roomController.currentlyHeating,
                roomController.targetHumidity, roomController.currentlyHumidifying);
            break;

        case '2':
            switch (newSensor(roomController.sensor)) {
            case SENSOR_NOT_VALID:
                cout << "Input was not valid and so was not added to system." << endl;
                break;
            case MAX_SENSORS_REACHED:
                cout << "The maximum number of sensors has already been given." << endl;
                break;
            }
            break;

        case '3':
            switch (updateSensor(roomController.sensor)) {
            case INVALID_SENSOR_SELECTED:
                cout << "Invalid sensor selected." << endl;
                break;
            }
            break;

        case '4':
            setTemperatureTarget(roomController.targetTemperature);
            break;

        case '5':
            setHumidityTarget(roomController.targetHumidity);
            break;

        case '6':
            return 0;
            break;

        default:
            cout << "Invalid Entry, please try again." << endl;
            break;
        }

        // Regardless of option chosen, check to see if controller should update values at the end.
        switch (checkValues(roomController.sensor,
            roomController.targetTemperature, roomController.currentlyHeating,
            roomController.targetHumidity, roomController.currentlyHumidifying)) {
        case HEATING_STATUS_CHANGED:
            // Ternary operator: (statement) ? (pick if true) : (pick if false)
            cout << "The heating is now " << (roomController.currentlyHeating ? "ON" : "OFF") << endl << endl;
            break;
        case HUMIDIFIER_STATUS_CHANGED:
            cout << "The humidifier is now " << (roomController.currentlyHumidifying ? "ON" : "OFF") << endl << endl;
            break;
        }
    }
}

// Allow the user to enter a new message and create the relevant packets
//   Arguments:
//     (1) the array of sensors
//     (2) the current target temperature in degrees C.
//     (3) a flag to indicate whether the controller is currently heating the room.
//     (4) the current target relative humidity in %
//     (5) a flag to indicate whether the controller is currently heating the room.
//   Returns: Nothing
void printStates(const Sensors sensorArray[], const float& targetTemperature, const bool& currentlyHeating, const float& targetHumidity, const bool& currentlyHumidifying) {
    uint16_t validSensorCount = 0;

    cout << "Sensors:" << endl;
    cout << "--------" << endl;

    // For each sensor, print its Type and Value
    for (uint16_t count = 0; count < MAX_NUM_SENSORS; count++) {
        if (sensorArray[count].valid) {
            validSensorCount++;
            cout << count << ". ";
            // Ternary operator: (statement) ? (pick if true) : (pick if false)
            cout << " Type: " << (sensorArray[count].type == TEMPERATURE ? "Temperature" : "Humidity");
            cout << " Value: " << sensorArray[count].value << endl;
        }
    }
    if (validSensorCount == 0) {
        cout << "There are no valid sensors, please add one first." << endl;
    }

    cout << endl;
    cout << "The heating is " << (currentlyHeating ? "ON" : "OFF") << endl;
    cout << "The target temperature is " << targetTemperature << " degrees C" << endl;
    cout << "The humidifier is " << (currentlyHumidifying ? "ON" : "OFF") << endl;
    cout << "The target humidity is " << targetHumidity << "%" << endl;
}

// Allow the user to enter a new message and create the relevant packets
//   Arguments:
//     (1) the array of sensors
//   Returns:
//     NEW_SENSOR - when a new sensor has been successfully defined.
//     SENSOR_NOT_VALID - when an incorrect type has been given.
//     MAX_SENSORS_REACHED - when too many sensors have been defined.
uint8_t newSensor(Sensors sensorArray[]) {
    uint16_t sensorType;
    float newValue;

    // Give new options to the user.
    cout << "Select Sensor Type" << endl;
    cout << "------------------" << endl;
    cout << "1. Temperature" << endl;
    cout << "2. Humidity" << endl;

    cout << "Enter your option [1-2]: "; cin >> sensorType;
    cout << endl;

    // Check if a correct option has been picked.
    if (sensorType != TEMPERATURE && sensorType != HUMIDTY) {
        return SENSOR_NOT_VALID;
    }
    cout << "What is the initial value of the sensor? "; cin >> newValue;
    cout << endl;

    // Iterate through the sensor array until we come across the next
    // undefined sensor.
    for (uint16_t count = 0; count < MAX_NUM_SENSORS; count++) {
        if (!sensorArray[count].valid) {
            sensorArray[count].type = sensorType;
            sensorArray[count].value = newValue;
            sensorArray[count].valid = true;
            return NEW_SENSOR;
        }
    }

    // We get to this area of the code only when all sensors in the array have
    // been defined.
    return MAX_SENSORS_REACHED;
}

// Allow the user to enter a new message and create the relevant packets
//   Arguments:
//     (1) the array of sensors
//   Returns:
//     OK - when a new sensor has been successfully update with a value.
//     INVALID_SENSOR_SELECTED - when an invalid sensor has been selected.
uint8_t updateSensor(Sensors sensorArray[]) {
    float newValue;
    uint16_t sensorIndex;

    // Give new options to the user.
    cout << endl << "Choose a valid sensor index: "; cin >> sensorIndex;
    cout << endl;

    // Check the index and exit if out of bounds or if the chosen sensor isn't valid.
    if ((sensorIndex >= MAX_NUM_SENSORS) || (sensorIndex < 0) || !sensorArray[sensorIndex].valid) {
        return INVALID_SENSOR_SELECTED;
    }

    cout << "What is the new value of the sensor? "; cin >> newValue;
    cout << endl;

    // Update the chosen sensor's value.
    sensorArray[sensorIndex].value = newValue;
    return OK;
}

// Allow the user to enter a new message and create the relevant packets
//   Arguments:
//     (1) the new target temperature for the room.
//   Returns: Nothing
void setTemperatureTarget(float& targetTemperature) {
    float newValue;

    // Take input from the user
    cout << "What is the new temperature target (degrees c)? "; cin >> newValue;
    cout << endl;

    // Set the chosen value
    targetTemperature = newValue;
}

// Allow the user to enter a new message and create the relevant packets
//   Arguments:
//     (1) the new target Humidity for the room.
//   Returns: Nothing
void setHumidityTarget(float& targetHumidity) {
    float newValue;

    // Take input from the user.
    cout << "What is the new humidity target? "; cin >> newValue;
    cout << endl;

    // Set the chosen value
    targetHumidity = newValue;
}

// Allow the user to enter a new message and create the relevant packets
//   Arguments:
//     (1) the array of sensors
//     (2) the current target temperature in degrees C.
//     (3) a flag to indicate whether the controller is currently heating the room.
//     (4) the current target relative humidity in %
//     (5) a flag to indicate whether the controller is currently heating the room.
//   Returns:
//       NO_CHANGE - When the status of the room controller has not changed.
//       HEATING_STATUS_CHANGED - When the heating should be turned off or on.
//       HUMIDIFIER_STATUS_CHANGED - When the humidfier should be turned on or off.
uint8_t checkValues(const Sensors sensor[], const float& targetTemperature, bool& currentlyHeating, const float& targetHumidity, bool& currentlyHumidifying) {
    float averageTemperature = 0;
    float averageHumidity = 0;
    uint16_t temperatureCount = 0;
    uint16_t humidityCount = 0;
    bool oldSwitch;

    // Iterate through each sensor
    for (uint16_t count = 0; count < MAX_NUM_SENSORS; count++) {
        if (sensor[count].valid) {
            if (sensor[count].type == TEMPERATURE) {
                //Temporarily accumulate each temperature value
                averageTemperature = averageTemperature + sensor[count].value;
                
                //Count the number of valid temperature sensors used in the total.
                temperatureCount++;
            }
            else {
                //Temporarily accumulate each humidity value
                averageHumidity = averageHumidity + sensor[count].value;

                //Count the number of valid humidity sensors used in the total.
                humidityCount++;
            }
        }
    }

    // If any temperature sensors existed...
    if (temperatureCount) {
        averageTemperature = averageTemperature / temperatureCount;

        // Store the previous value of the heating flag.
        oldSwitch = currentlyHeating;

        // Apply boolean logic to set the heater flag.
        currentlyHeating = (averageTemperature < targetTemperature);

        // Return specific type only if status has changed.
        if (oldSwitch != currentlyHeating) {
            return HEATING_STATUS_CHANGED;
        }
    }

    // If any humidity sensors existed...
    if (humidityCount) {
        averageHumidity = averageHumidity / humidityCount;

        // Store the previous value of the humidifier flag.
        oldSwitch = currentlyHumidifying;

        // Apply boolean logic to set the humidifier flag.
        currentlyHumidifying = (averageHumidity < targetHumidity);
        if (oldSwitch != currentlyHumidifying) {
            return HUMIDIFIER_STATUS_CHANGED;
        }
    }
    return NO_CHANGE;
}