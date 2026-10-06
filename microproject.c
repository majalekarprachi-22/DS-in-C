#include <stdio.h>
#include <string.h>

struct Order
{
    int orderID;
    char customerName[50];
    char productName[50];
    int quantity;
    float unitPrice;
    char status[20];
    char orderDate[20];
};

struct Order orders[1000];
int count = 0;

/* Function to calculate final order amount */
float calculateTotal(struct Order o)
{
    float total, discount = 0;

    total = o.quantity * o.unitPrice;

    if (total > 5000)
    {
        discount = total * 0.10;
    }

    return total - discount;
}

/* Add a new order */
void addOrder()
{
    printf("\nEnter Order ID: ");
    scanf("%d", &orders[count].orderID);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", orders[count].customerName);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", orders[count].productName);

    printf("Enter Quantity: ");
    scanf("%d", &orders[count].quantity);

    printf("Enter Unit Price: ");
    scanf("%f", &orders[count].unitPrice);

    printf("Enter Order Status (Pending/Shipped/Delivered): ");
    scanf("%s", orders[count].status);

    printf("Enter Order Date (DD-MM-YYYY): ");
    scanf("%s", orders[count].orderDate);

    count++;

    printf("\nOrder added successfully!\n");
}

/* Display all orders */
void displayOrders()
{
    int i;

    if (count == 0)
    {
        printf("\nNo orders available.\n");
        return;
    }

    printf("\n-------------- ALL ORDERS ----------------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nOrder ID      : %d", orders[i].orderID);
        printf("\nCustomer Name : %s", orders[i].customerName);
        printf("\nProduct Name  : %s", orders[i].productName);
        printf("\nQuantity      : %d", orders[i].quantity);
        printf("\nUnit Price    : %.2f", orders[i].unitPrice);
        printf("\nStatus        : %s", orders[i].status);
        printf("\nOrder Date    : %s", orders[i].orderDate);
        printf("\nFinal Amount  : %.2f\n", calculateTotal(orders[i]));
    }
}

/* Calculate total for a particular order */
void showOrderTotal()
{
    int id, i, found = 0;
    float total, discount, finalAmount;

    printf("\nEnter Order ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (orders[i].orderID == id)
        {
            found = 1;

            total = orders[i].quantity * orders[i].unitPrice;

            if (total > 5000)
            {
                discount = total * 0.10;
            }
            else
            {
                discount = 0;
            }

            finalAmount = total - discount;

            printf("\nOrder ID      : %d", orders[i].orderID);
            printf("\nOriginal Total: %.2f", total);
            printf("\nDiscount      : %.2f", discount);
            printf("\nFinal Amount  : %.2f\n", finalAmount);

            break;
        }
    }

    if (found == 0)
    {
        printf("\nOrder not found.\n");
    }
}

/* Update order status */
void updateStatus()
{
    int id, i, found = 0;

    printf("\nEnter Order ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (orders[i].orderID == id)
        {
            found = 1;

            if (strcmp(orders[i].status, "Pending") == 0)
            {
                strcpy(orders[i].status, "Shipped");
                printf("\nOrder status updated: Pending -> Shipped\n");
            }
            else if (strcmp(orders[i].status, "Shipped") == 0)
            {
                strcpy(orders[i].status, "Delivered");
                printf("\nOrder status updated: Shipped -> Delivered\n");
            }
            else if (strcmp(orders[i].status, "Delivered") == 0)
            {
                printf("\nOrder is already Delivered.\n");
            }
            else
            {
                printf("\nInvalid order status.\n");
            }

            break;
        }
    }

    if (found == 0)
    {
        printf("\nOrder not found.\n");
    }
}

/* Convert date DD-MM-YYYY to number of days */
int dateToDays(char date[])
{
    int day, month, year;

    sscanf(date, "%d-%d-%d", &day, &month, &year);

    return year * 365 + month * 30 + day;
}

/* Display pending orders older than 3 days */
void displayDelayedOrders()
{
    char today[20];
    int todayDays, orderDays, difference;
    int i, found = 0;

    printf("\nEnter Today's Date (DD-MM-YYYY): ");
    scanf("%s", today);

    todayDays = dateToDays(today);

    printf("\n========== DELAYED ORDERS ==========\n");

    for (i = 0; i < count; i++)
    {
        orderDays = dateToDays(orders[i].orderDate);
        difference = todayDays - orderDays;

        if (strcmp(orders[i].status, "Pending") == 0 &&
            difference > 3)
        {
            found = 1;

            printf("\nOrder ID      : %d", orders[i].orderID);
            printf("\nCustomer Name : %s", orders[i].customerName);
            printf("\nProduct Name  : %s", orders[i].productName);
            printf("\nOrder Date    : %s", orders[i].orderDate);
            printf("\nStatus        : Delayed\n");
        }
    }

    if (found == 0)
    {
        printf("\nNo delayed orders found.\n");
    }
}

/* Calculate total revenue from delivered orders */
void totalRevenue()
{
    int i;
    float revenue = 0;

    for (i = 0; i < count; i++)
    {
        if (strcmp(orders[i].status, "Delivered") == 0)
        {
            revenue = revenue + calculateTotal(orders[i]);
        }
    }

    printf("\nTotal Revenue from Delivered Orders = %.2f\n", revenue);
}

/* Search order */
void searchOrder()
{
    int id, i, found = 0;

    printf("\nEnter Order ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (orders[i].orderID == id)
        {
            found = 1;

            printf("\nOrder Found!\n");
            printf("Order ID      : %d\n", orders[i].orderID);
            printf("Customer Name : %s\n", orders[i].customerName);
            printf("Product Name  : %s\n", orders[i].productName);
            printf("Quantity      : %d\n", orders[i].quantity);
            printf("Unit Price    : %.2f\n", orders[i].unitPrice);
            printf("Status        : %s\n", orders[i].status);
            printf("Order Date    : %s\n", orders[i].orderDate);

            break;
        }
    }

    if (found == 0)
    {
        printf("\nOrder not found.\n");
    }
}

/* Main function */
int main()
{
    int choice;

    do
    {
        printf("\n---------ONLINE SHOPPING ORDER MANAGEMENT SYSTEM--------");
        printf("\n1. Add Order");
        printf("\n2. Display All Orders");
        printf("\n3. Calculate Order Total");
        printf("\n4. Update Order Status");
        printf("\n5. Display Delayed Orders");
        printf("\n6. Calculate Total Revenue");
        printf("\n7. Search Order");
        printf("\n8. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addOrder();
                break;

            case 2:
                displayOrders();
                break;

            case 3:
                showOrderTotal();
                break;

            case 4:
                updateStatus();
                break;

            case 5:
                displayDelayedOrders();
                break;

            case 6:
                totalRevenue();
                break;

            case 7:
                searchOrder();
                break;

            case 8:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}