
#include <stdio.h>
#include <ctype.h>
 
int main()
{
    int zoneA = 20, zoneB = 40, zoneC = 15;
    int occ_a = 0, occ_b = 0, occ_c = 0;
    int total_processed = 0, total_accepted = 0, total_rejected = 0;
    int cars_parked = 0, bikes_parked = 0, vans_parked = 0;
 
    printf("Enter the total number of vehicles for process: ");
    scanf("%d", &total_processed);
 
    int remaining_vehicles = total_processed;
 
    while (remaining_vehicles--)
    {
        char vehicle_type;
        printf("\nEnter the vehicle type (C for Car, B for Bike, V for Van): ");
        scanf(" %c", &vehicle_type);
        vehicle_type = toupper((unsigned char) vehicle_type);
        while (vehicle_type != 'C' && vehicle_type != 'B' && vehicle_type != 'V')
        {
            printf("Invalid vehicle type. Please enter C, B, or V: ");
            scanf(" %c", &vehicle_type);
            vehicle_type = toupper((unsigned char) vehicle_type);
        }
 
        char user_category;
        printf("Enter the user category (F for Faculty, S for Student, G for Visitor): ");
        scanf(" %c", &user_category);
        user_category = toupper((unsigned char) user_category);
        while (user_category != 'F' && user_category != 'S' && user_category != 'G')
        {
            printf("Invalid user category. Please enter F, S, or G: ");
            scanf(" %c", &user_category);
            user_category = toupper((unsigned char) user_category);
        }
 
        char permit_status;
        printf("Enter the permit status (Y for Yes, N for No): ");
        scanf(" %c", &permit_status);
        permit_status = toupper((unsigned char) permit_status);
        while (permit_status != 'Y' && permit_status != 'N')
        {
            printf("Invalid permit status. Please enter Y or N: ");
            scanf(" %c", &permit_status);
            permit_status = toupper((unsigned char) permit_status);
        }
 
        char emergency_status;
        printf("Is this an emergency vehicle? (Y for Yes, N for No): ");
        scanf(" %c", &emergency_status);
        emergency_status = toupper((unsigned char) emergency_status);
        while (emergency_status != 'Y' && emergency_status != 'N')
        {
            printf("Invalid emergency status. Please enter Y or N: ");
            scanf(" %c", &emergency_status);
            emergency_status = toupper((unsigned char) emergency_status);
        }
 
        if (permit_status == 'N' && emergency_status != 'Y')
        {
            total_rejected++;
            printf("Rejected: no valid permit and not an emergency vehicle.\n");
            continue;
        }
 
        int required_spaces;
        if (vehicle_type == 'V') required_spaces = 2; else required_spaces = 1;
        int assigned_zone = 0; 
        if (user_category == 'F')
        {
          
            if ((zoneA - occ_a) >= required_spaces) assigned_zone = 1;
        }
        else if (user_category == 'S')
        {
            if (vehicle_type == 'V')
            {
            
                if ((zoneC - occ_c) >= required_spaces) assigned_zone = 3;
            }
            else
            {
                if ((zoneB - occ_b) >= required_spaces) assigned_zone = 2;
            }
        }
        else 
        {
            
            if ((zoneC - occ_c) >= required_spaces) assigned_zone = 3;
        }
 
        if (assigned_zone == 0)
        {
            total_rejected++;
            printf("Rejected: no available space in the required zone.\n");
            continue;
        }
 
        total_accepted++;
        if (vehicle_type == 'C') cars_parked++;
        else if (vehicle_type == 'B') bikes_parked++;
        else vans_parked++;
 
        if (assigned_zone == 1)
        {
            occ_a += required_spaces;
            printf("Success: Assigned to Zone A. Remaining capacity: %d\n", zoneA - occ_a);
        }
        else if (assigned_zone == 2)
        {
            occ_b += required_spaces;
            printf("Success: Assigned to Zone B. Remaining capacity: %d\n", zoneB - occ_b);
        }
        else
        {
            occ_c += required_spaces;
            printf("Success: Assigned to Zone C. Remaining capacity: %d\n", zoneC - occ_c);
        }
    }
 
    printf("\n=== CAMPUS PARKING SUMMARY ===\n");
    printf("Total vehicles processed: %d\n", total_processed);
    printf("Total vehicles accepted: %d\n", total_accepted);
    printf("Total vehicles rejected: %d\n", total_rejected);
    printf("Total cars parked: %d\n", cars_parked);
    printf("Total bikes parked: %d\n", bikes_parked);
    printf("Total vans parked: %d\n", vans_parked);
 
    printf("\nFinal Occupancy / Capacity:\n");
    printf("Zone A: %d / %d (Remaining: %d)\n", occ_a, zoneA, zoneA - occ_a);
    printf("Zone B: %d / %d (Remaining: %d)\n", occ_b, zoneB, zoneB - occ_b);
    printf("Zone C: %d / %d (Remaining: %d)\n", occ_c, zoneC, zoneC - occ_c);
 
    if (occ_a > occ_b && occ_a > occ_c)
        printf("\nZone A has the highest occupancy.\n");
    else if (occ_b > occ_a && occ_b > occ_c)
        printf("\nZone B has the highest occupancy.\n");
    else if (occ_c > occ_a && occ_c > occ_b)
        printf("\nZone C has the highest occupancy.\n");
    else
        printf("\nMultiple zones share the highest occupancy or all are empty.\n");
 
    if (occ_a == zoneA && occ_b == zoneB && occ_c == zoneC)
        printf("Entire campus parking facility is FULL.\n");
    else
        printf("Campus parking facility is NOT full.\n");
 
    return 0;
}
 
