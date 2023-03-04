def symptom_similarity(symptomsA, symptomsB):
    """
    Compute symptom similiarity between patients A and B.

    Args:
        symptomsA: a tuple (present, absent) for patient A
                   where present is a set of symptoms present
                   and absent is a set of symptoms absent
        symptomsB: Same format as above but for patient B

    Returns:
        integer, symptom similiarity between the patients
    """
    present_present = len(symptomsA[0] & symptomsB[0])
    absent_absent = len(symptomsA[1] & symptomsB[1])
    present_absent = len(symptomsA[0] & symptomsB[1])
    absent_present = len(symptomsA[1] & symptomsB[0])
    return present_present + absent_absent - present_absent - absent_present


def similarity_to_patients(patient_symptoms, all_patients_symptoms):
    """Finds patients who have highest similarity of symptoms with a given patient.
    Args:
        patient_symptoms: tuple of symptoms present and absent for a given patient.
        all_patients_symptoms: dictionary of patients IDs (key) and associated tuple of
                               present and absent symptoms for all patients.
    Returns:
        set of patient IDs, who have highest similarity with the given patient.
    """

    # Initialize max_similarity to 0
    max_similarity = 0

    # Iterate though each patient in the all_patients_symptoms
    for patient_id in all_patients_symptoms.keys():
        # Calculate similarity between current patient and the given patient
        similarity = symptom_similarity(patient_symptoms, all_patients_symptoms.get(patient_id))

        # If the similarity is greater than the max_similarity
        if max_similarity < similarity:
            # Update the max_similarity
            max_similarity = similarity

    # Initialize result as an empty set
    result = set()

    # Iterate though each patient in the all_patients_symptoms
    for patient_id in all_patients_symptoms.keys():
        # Calculate similarity between current patient and the given patient
        similarity = symptom_similarity(patient_symptoms, all_patients_symptoms.get(patient_id))

        # If the similarity is equal to max_similarity
        if max_similarity == similarity:
            # Add current patient to result set
            result.add(patient_id)

    # Return result
    return result


def getting_diagnostics(patient_set, all_patients_diagnostics):
    """Find most frequent diagnostic among patients in patient_set.
    Args:
        patient_set: A set of patient IDs
        all_patients_diagnostics: A dictionary with key = patient_ID
                               and value = diagnostic
    Returns: the most frequent diagnostic (a string)
    """

    # Initialize diagnostic_freq to empty dictionary
    diagnostic_freq = {}

    # Iterate through each patient in the patient_set
    for patient_id in patient_set:
        # Get the diagnostic of the current patient
        diagnostic = all_patients_diagnostics.get(patient_id)

        # If the diagnostic already exists in the diagnostic_freq dictionary
        if diagnostic in diagnostic_freq.keys():
            # Increment value of that diagnostic by 1
            diagnostic_freq[diagnostic] += 1

        # If the diagnostic does not exist in the diagnostic_freq dictionary
        else:
            # Add diagnostic to diagnostic_freq dictionary and set the value as 1
            diagnostic_freq[diagnostic] = 1

    # Initialize max_count to 0
    max_count = 0
    # Initialize max_diagnostic as an empty string
    max_diagnostic = ""

    # Iterate through each diagnostic in diagnostic_freq dictionary
    for diagnostic in diagnostic_freq.keys():

        # Select the diagnostic with the max frequency
        if max_count < diagnostic_freq.get(diagnostic):
            max_count = diagnostic_freq.get(diagnostic)
            max_diagnostic = diagnostic

    # Return the diagnostic with maximum frequency
    return max_diagnostic


if __name__ == "__main__":
    # patientID: (set of symptoms present, set of symptoms absent)
    all_patients_symptoms = {
        56374: ({"headache", "fever"},
                {"coughing", "runny_nose", "sneezing"}),
        45437: ({"coughing", "runny_nose"},
                {"headache", "fever"}),
        16372: ({"coughing", "sore_throat"},
                {"fever"}),
        54324: ({"vomiting", "coughing", "stomach_pain"},
                {"fever"}),
        73454: ({"coughing", "runny_nose"},
                {"headache", "fever"}),
        35249: ({"sore_throat", "coughing", "fever"},
                {"stomach_pain", "runny_nose"}),
        44274: ({"fever", "headache"},
                {"stomach_pain", "runny_nose", "sore_throat", "coughing"}),
        74821: ({"vomiting", "fever"},
                {"headache"}),
        94231: ({"stomach_pain", "fever", "sore_throat", "coughing", "headache"},
                {"vomiting"})
    }

    # patientID: diagnostic
    all_patients_diagnostics = {
        45437: "cold",
        56374: "meningitis",
        54324: "food_poisoning",
        16372: "cold",
        73454: "cold",
        35249: "pharyngitis",
        44274: "meningitis",
        74821: "food_poisoning",
        94231: "pharyngitis",
    }

    # Three test patients:
    # (set of symptoms present, set of symptoms absent)
    patientA = ({"coughing", "runny_nose", "sneezing"}, {"headache", "fever"})
    patientB = ({"coughing", "fever", "sore_throat", "sneezing"}, {"muscle_pain"})
    patientC = ({"headache"}, {"sneezing"})

    # Testing function similarity_to_patients
    simA = similarity_to_patients(patientA, all_patients_symptoms)
    print(simA)  # {45437, 73454}

    simB = similarity_to_patients(patientB, all_patients_symptoms)
    print(simB)  # {35249, 94231}

    simC = similarity_to_patients(patientC, all_patients_symptoms)
    print(simC)  # {56374}

    # Testing getting_diagnostics
    simX = {45437, 56374, 16372}
    diagX = getting_diagnostics(simX, all_patients_diagnostics)
    print(diagX)  # cold
    # In this example above, frequencies of diagnostics would be:
    # {'cold': 2, 'meningitis': 1}
    # So "cold" was returned as it has max frequency.

    simY = {35249, 94231}
    diagY = getting_diagnostics(simY, all_patients_diagnostics)
    print(diagY)  # pharyngitis

    simZ = {56374, 74821, 44274}
    diagZ = getting_diagnostics(simZ, all_patients_diagnostics)
    print(diagZ)  # meningitis
