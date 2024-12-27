#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registerUser();
void loginUser();
void addCar();
void viewCars();
void rentCar();
void viewRentals();
void deleteCar();
void updateCar();

// Structure to hold user details
typedef struct 
{ 
    char username[50]; 
    char password[50]; 
} User;

// Structure to hold car details
typedef struct 
 {
    int id;
    char brand[50];
    char model[50];
    float price_per_day;
}Car ;

// Structure to hold rental details
typedef struct {
    char customer_name[50];
    int car_id;
    int rental_days;
    float total_cost;
} Rental;

int main() 
{      
    int choice;
    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);  
switch (choice) 
{
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    return 0;
}
}
// Function to add new user
void registerUser() 
{
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
else
{
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);
    printf("User registered successfully!\n");
}
}
//function to login
void loginUser() 
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) 
    {
        printf("Could not open file for reading.\n");
        return ;
    }
else 

{
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    User user;
    while (fscanf(file, "%s %s", user.username, user.password) != EOF) 
    {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) 
        {
            printf("Login successful!\n");
            fclose(file);
              int ch;
                while (1) 
            {
                    printf("\nCar Rental System\n");
                    printf("1. Add Car\n");
                    printf("2. View Cars\n");
	printf("3.Delete car\n");
	printf("4.Update car\n");
                    printf("5. Rent Car\n");
                    printf("6. View Rentals\n");
                    printf("7. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &ch);
                switch (ch)
        {
                    case 1:
                        addCar();
                        break;
                    case 2:
                        viewCars();
                        break;
                    case 3:
	    deleteCar();
                        break;
                    case 4:
	    updateCar();
                        break;
                    case 5:
                        rentCar();
	    break;
                    case 6:
                        viewRentals();
	    break;
                    case 7:
                        printf("Exiting...\n");
                        exit(0);
                    default:
                        printf("Invalid choice. Try again.\n");
                }
            }	
            return ;
        }
        else
        {
            printf("invalid username password");
        }
    }
}
}

// Function to add a car
void addCar() {
    FILE *file = fopen("cars.txt", "a");    
if (file == NULL) 
{
        printf("Could not open file  for appending.\n");
        return ;
    }
else
{
    Car car;
    printf("Enter car ID: ");
    scanf("%d", &car.id);
    printf("Enter car brand: ");
    scanf("%s", &car.brand);
    printf("Enter car model: ");
    scanf("%s",&car.model);
    printf("Enter price per day: ");
    scanf("%f", &car.price_per_day);

    fprintf(file, "%d,%s,%s,%f\n", car.id, car.brand, car.model, car.price_per_day);
    fclose(file);
    printf("Car added successfully!\n");
}
}
//function to delete car
void deleteCar() {
    FILE *file = fopen("cars.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
else
{
    Car cars[100];
    int count = 0;
    while (fscanf(file, "%d %s %s %f", &cars[count].id, cars[count].brand, cars[count].model,cars[count].price_per_day) != EOF) {
        count++;
    }
    fclose(file);

    int carID;
    printf("Enter car ID to delete: ");
    scanf("%d", &carID);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (cars[i].id == carID) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                cars[j] = cars[j + 1];
            }
            count--;
            break;
        }
    }

    if (found) {
        file = fopen("cars.txt", "w");
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d %s %s %f", &cars[i].id, cars[i].brand, cars[i].model,cars[i].price_per_day);
        }
        fclose(file);
        printf("Car deleted successfully!\n");
    } else {
        printf("Car ID not found.\n");
    }
}
}
// Function to update car 
void updateCar() {
    FILE *file = fopen("cars.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }
else
{
    Car cars[100];
    int count = 0;
    while (fscanf(file, "%d %s %s %f", &cars[count].id, cars[count].brand, cars[count].model, &cars[count].price_per_day) != EOF) {
        count++;
    }
    fclose(file);

    int carID;
    printf("Enter car ID to update: ");
    scanf("%d", &carID);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (cars[i].id == carID) {
            found = 1;
            printf("Enter new brand: ");
            scanf("%s", cars[i].brand);
            printf("Enter new model: ");
            scanf("%s", cars[i].model);
            printf("Enter new price per day: ");
            scanf("%f", &cars[i].price_per_day);
            break;
        }
    }

    if (found) {
        file = fopen("cars.txt", "w");
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d %s %s %f\n", cars[i].id, cars[i].brand, cars[i].model, cars[i].price_per_day);
        }
        fclose(file);
        printf("Car updated successfully!\n");
    } else {
        printf("Car ID not found.\n");
    }
}
}


//Function to view car
void viewCars() 
{
    FILE *file = fopen("cars.txt", "r");
    if (!file) 
{
        printf("No cars found.\n");
        return ;
    }
else
{
    Car car;
    printf("\nAvailable Cars:\n");
    printf("ID\tBrand\tModel\tPrice/Day\n");
    while (fscanf(file, "%d,%49[^,],%49[^,],%f\n", &car.id, car.brand, car.model, &car.price_per_day) != EOF) {
	printf("%d\t%s\t%s\t%f\n", car.id, car.brand, car.model, car.price_per_day);
    }
    fclose(file);
}
}

// Function to rent a car
void rentCar() 
{
    int carId, days;
    float cost;
    char customerName[50];
    FILE *file = fopen("rentals.txt", "a");
    if (!file) 
{
        printf("Error opening file.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s",&customerName);
    printf("Enter car ID to rent: ");
    scanf("%d", &carId);
    printf("Enter number of days: ");
    scanf("%d", &days);

    // Calculate payment
    FILE *carFile = fopen("cars.txt", "r");
    if (!carFile) {
        printf("No cars available for rent.\n");
        fclose(file);
        return;
    }

else
{
    Car car;
    int found = 0;
    while (fscanf(carFile, "%d,%49[^,],%49[^,],%f\n", &car.id, car.brand, car.model, &car.price_per_day) != EOF) 
{
        if (car.id == carId) {
            found = 1;
            cost = car.price_per_day * days;
            break;
        }
    }
    fclose(carFile);
    if (!found) 
{
        printf("Car ID not found.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%s,%d,%d,%f\n", customerName, carId, days, cost);
    fclose(file);

    printf("Car rented successfully! Total cost: %f\n", cost);
}
}


// Function to view all rentals
void viewRentals() 
{
    FILE *file = fopen("rentals.txt", "r");
    if (file==NULL) {
        printf("No rental records found.\n");
        return;
    }
else
{
    Rental rental;
    printf("\nRental Records:\n");
    printf("Customer Name\tCar ID\tDays\tTotal Cost\n");
    while (fscanf(file, "%49[^,],%d,%d,%f\n", rental.customer_name, &rental.car_id, &rental.rental_days, &rental.total_cost) != EOF) {
        printf("%s    \t%d\t%d\t%f\n", rental.customer_name, rental.car_id, rental.rental_days, rental.total_cost);
    }
    fclose(file);
}
}