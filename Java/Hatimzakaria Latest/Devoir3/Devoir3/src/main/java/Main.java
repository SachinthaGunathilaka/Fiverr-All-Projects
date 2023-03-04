//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by FernFlower decompiler)
//

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public Main() {
    }

    public static void main(String[] args) throws IOException {
        init();
        MemberController memberController = new MemberController();
        ActivityController activityController = new ActivityController();


        String MenuPrincipal = "\nBienvenue sur notre Plateforme.\n[1] Acces au account\n[2] Creer un account\n[3] Quitter la plateforme\nChoisir un chiffre et appuyer sur entrer : ";
        String MenuActivites = "\nSelectionner une option parmis les choix suivant:\n[1] Gestion du account\n[2] Gestion d'outils\n[3] Gestion d'articles\n[4] Gestion des projets\n[5] Quitter ou retourne au page precedent\nChoisir un chiffre et appuyer sur entrer : ";
        String MenuValidationCompte = "\nBienvenue sur notre Plateforme.\n[1] Creer un account\n[2] Acceptation d'un compre par le proffesseur\n[3] Validation d'un account par l'adminstrateur \n[4] Quitter ou retourne au page precedent\nChoisir un chiffre et appuyer sur entrer : ";
        String GestionCompte = "\nSelectionner une option parmis les choix suivant:\n[1] Afficher le profil d'un membre\n[2] Afficher la liste des membres\n[3] Afficher la liste des membres associes à un interet\n[4] Afficher la liste des activites associes à un interet \n[5] Quitter ou retourne au page precedent\nChoisir un chiffre et appuyer sur entrer : ";
        String GestionOutils = "\nSelectionner une option parmis les choix suivant:\n[1] Afficher la liste des outils\n[2] Afficher le profil d'un outil\n[3] Creer un outil \n[4] Modifier un outil\n[5] Supprimer un outil\n[6] Quitter ou retourne au page precedent\nChoisir un chiffre et appuyer sur entrer : ";
        String GestionArticles = "\nSelectionner une option parmis les choix suivant:\n[1] Afficher la liste des articles\n[2] Afficher la fiche complet d'un article\n[3] Ajouter un article \n[4] Modifier un article\n[5] Supprimer un article\n[6] Quitter ou retourne au page precedent\nChoisir un chiffre et appuyer sur entrer : ";
        String GestionProjets = "\nSelectionner une option parmis les choix suivant:\n[1] Afficher la liste des projets\n[2] Afficher la fiche complet d'un projet \n[3] Creer un projet \n[4] Modifier un projet\n[5] Supprimer un projet\n[6] Quitter ou retourne au page precedent\nChoisir un chiffre et appuyer sur entrer : ";
        Scanner scan = new Scanner(System.in);

        boolean main_loop = true;

        while (main_loop) {
            System.out.print(MenuPrincipal);
            int a = Integer.parseInt(scan.nextLine());
            int c;
            switch (a) {
                case 1:
                    boolean loop1 = true;
                    while (loop1) {

                /*
                            Selectionner une option parmis les choix suivant:
                            [1] account Management
                            [2] Utility Management
                            [3] Article Management
                            [4] Project Management
                            [5] Quitter or break to the previous page
                            Choisir un chiffre et appuyer sur entrer
                 */

                        System.out.print(MenuActivites);
                        int b = Integer.parseInt(scan.nextLine());
                        switch (b) {
                            case 1:
                                boolean loop11 = true;
                                while (loop11) {

                        /*
                            [1] Display the profile of a member
                            [2] Display the list of members
                            [3] View the list of members associated with an interest
                            [4] View the list of activities associated with an interest
                            [5] Quitter or break to the previous page
                         */
                                    System.out.print(GestionCompte);
                                    c = Integer.parseInt(scan.nextLine());
                                    switch (c) {
                                        case 1:
//                                System.out.println("methode pour afficher le profil d'un membres.....");
                                            System.out.print("Enter email : ");
                                            String email = scan.nextLine();
                                            memberController.displayMember(email);

                                            break;
                                        case 2:
//                                System.out.println("methode pour afficher liste des membres .....");
                                            memberController.displayMembers();
                                            break;
                                        case 3:
                                            System.out.println("No students associated with interests");
                                            break;
                                        case 4:
                                            System.out.println("No activities associated with interests");
                                            break;
                                        case 5:
                                            System.out.println("retourne au page precedent ou quitter....");
                                            loop11 = false;
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            case 2:
                                boolean loop12 = true;
                                while (loop12) {

                        /*
                                [1] Post the list of tools
                                [2] Display the profile of a tool
                                [3] Create a tool
                                [4] Modify a tool
                                [5] Delete a tool
                                [6] Quitter or break to the previous page
                         */
                                    System.out.print(GestionOutils);
                                    int d = Integer.parseInt(scan.nextLine());
                                    switch (d) {
                                        case 1:
//                                            System.out.println("methode pour afficher la liste des outils.....");
                                            activityController.displayTools();
                                            break;
                                        case 2:
//                                            System.out.println("methode pour afficher le profil d'un outil .....");
                                            System.out.print("Enter the tool title : ");
                                            String title = scan.nextLine();

                                            activityController.displayTool(title);
                                            break;
                                        case 3:
//                                            System.out.println("methode pour creer un outil.....");
                                            String description, version, repo;
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            System.out.print("Enter description : ");
                                            description = scan.nextLine();

                                            System.out.print("Enter version : ");
                                            version = scan.nextLine();

                                            System.out.print("Enter repo : ");
                                            repo = scan.nextLine();

                                            activityController.createTool(title, description, version, repo);

                                            break;
                                        case 4:
//                                            System.out.println("methode pour modifier un outil.....");
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            System.out.print("Enter description : ");
                                            description = scan.nextLine();

                                            System.out.print("Enter version : ");
                                            version = scan.nextLine();

                                            System.out.print("Enter repo : ");
                                            repo = scan.nextLine();

                                            activityController.updateTool(title, description, version, repo);

                                            break;
                                        case 5:
//                                            System.out.println("methode pour supprimer un outil.....");
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            activityController.deleteTool(title);
                                            break;
                                        case 6:
                                            System.out.println("retourne au page precedent ou quitter....");
                                            loop12 = false;
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            case 3:
                                boolean loop13 = true;
                                while (loop13) {

                        /*
                        [1] View the list of articles
                        [2] View the complete file of an article
                        [3] Add an article
                        [4] Modify an article
                        [5] Delete an article
                        [6] Quitter or break to the previous page
                         */
                                    System.out.print(GestionArticles);
                                    int e = Integer.parseInt(scan.nextLine());
                                    switch (e) {
                                        case 1:
                                            activityController.displayArticles();
                                            break;
                                        case 2:
                                            System.out.print("Enter the article title : ");
                                            String title = scan.nextLine();

                                            activityController.displayArticle(title);
                                            break;
                                        case 3:
                                            String description, url;
                                            ArticleStatus status;
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            System.out.print("Enter description : ");
                                            description = scan.nextLine();


                                            System.out.println("\t1) DRAFT\n" +
                                                    "\t2) READY\n" +
                                                    "\t3) SUBMITTED\n" +
                                                    "\t4) PUBLISHED\n" +
                                                    "\t5) REJECTED");
                                            System.out.print("Select status : ");
                                            int option = Integer.parseInt(scan.nextLine());
                                            while (option < 1 || option > 5) {
                                                System.out.println("Invalid status!");
                                                System.out.print("Select status : ");
                                                option = Integer.parseInt(scan.nextLine());
                                            }
                                            status = ArticleStatus.values()[option];

                                            System.out.print("Enter url : ");
                                            url = scan.nextLine();

                                            activityController.createArticle(title, description, status, url);

                                            break;
                                        case 4:
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            System.out.print("Enter description : ");
                                            description = scan.nextLine();


                                            System.out.println("\t1) DRAFT\n" +
                                                    "\t2) READY\n" +
                                                    "\t3) SUBMITTED\n" +
                                                    "\t4) PUBLISHED\n" +
                                                    "\t5) REJECTED");
                                            System.out.print("Select status : ");
                                            option = Integer.parseInt(scan.nextLine());
                                            while (option < 1 || option > 5) {
                                                System.out.println("Invalid status!");
                                                System.out.print("Select status : ");
                                                option = Integer.parseInt(scan.nextLine());
                                            }
                                            status = ArticleStatus.values()[option];

                                            System.out.print("Enter url : ");
                                            url = scan.nextLine();

                                            activityController.updateArticle(title, description, status, url);

                                            break;
                                        case 5:
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            activityController.deleteArticle(title);
                                            break;
                                        case 6:
                                            System.out.println("retourne au page precedent ou quitter....");
                                            loop13 = false;
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            case 4:
                                boolean loop14 = true;
                                while (loop14) {
                        /*
                            [1] View the list of projects
                            [2] View the complete file of a project
                            [3] Create a project
                            [4] Modify a project
                            [5] Delete a project
                            [6] Quitter or break to the previous page
                         */
                                    System.out.print(GestionProjets);
                                    int f = Integer.parseInt(scan.nextLine());
                                    switch (f) {
                                        case 1:
                                            activityController.displayProjects();
                                            break;
                                        case 2:
                                            System.out.print("Enter the project title : ");
                                            String title = scan.nextLine();

                                            activityController.displayProject(title);
                                            break;
                                        case 3:
                                            String description, startDate, endDate;
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            System.out.print("Enter description : ");
                                            description = scan.nextLine();

                                            System.out.print("Enter start date : ");
                                            startDate = scan.nextLine();

                                            System.out.print("Enter end date : ");
                                            endDate = scan.nextLine();

                                            activityController.createProject(title, description, startDate, endDate);
                                            break;
                                        case 4:
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            System.out.print("Enter description : ");
                                            description = scan.nextLine();

                                            System.out.print("Enter start date : ");
                                            startDate = scan.nextLine();

                                            System.out.print("Enter end date : ");
                                            endDate = scan.nextLine();

                                            activityController.updateProject(title, description, startDate, endDate);

                                            break;
                                        case 5:
                                            System.out.print("Enter title : ");
                                            title = scan.nextLine();

                                            activityController.deleteProject(title);
                                            break;
                                        case 6:
                                            System.out.println("retourne au page precedent ou quitter....");
                                            loop14 = false;
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            case 5:
                                System.out.println("retourne au page precedent....");
                                loop1 = false;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 2:
                    boolean loop2 = true;
                    while (loop2) {
                /*
                    [1] Create a account
                    [2] Acceptance of a purchase by the teacher
                    [3] Validation of a account by the administrator
                    [5] Quitter or break to the previous page
                 */
                        System.out.print(MenuValidationCompte);
                        c = Integer.parseInt(scan.nextLine());
                        switch (c) {
                            case 1:
                                String fname, lname, email, phoneNumber, password, role;
                                System.out.print("Enter firstname : ");
                                fname = scan.nextLine();

                                System.out.print("Enter lastname : ");
                                lname = scan.nextLine();

                                System.out.print("Enter email : ");
                                email = scan.nextLine();

                                System.out.print("Enter phone number : ");
                                phoneNumber = scan.nextLine();

                                System.out.print("Enter password : ");
                                password = scan.nextLine();

                                System.out.print("Enter role : ");
                                role = scan.nextLine();

                                Member member = new Member(fname, lname, email, phoneNumber, password, role);
                                User user = new User(member);
                                if (UserService.getInstance().addUser(user)) {
                                    System.out.println("User account created successfully!");
                                } else {
                                    System.out.println("User account already exists!");

                                }


                                break;
                            case 2:
                                System.out.println("No purchases for now");
                                break;
                            case 3:
                                memberController.showNotValidatedAccounts();

                                System.out.print("\nEnter email to validate : ");
                                email = scan.nextLine();

                                memberController.validateAccount(email);
//                                System.out.println("method pour Validation un account en cour.....");
                                break;
                            case 4:
                                System.out.println("retourne au page precedent....");
                                loop2 = false;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case 3:
                    System.out.println("Au revoir");
                    main_loop = false;
                    break;

                default:
                    System.out.println("Invalid input!");
            }

        }

        store();
    }

    public static void init() throws IOException {
        UserService userService = UserService.getInstance();
        userService.loadUsers("Database CSV.csv");
    }

    public static void store() {
        UserService userService = UserService.getInstance();
        userService.storeUsers("Database CSV.csv");
    }
}

