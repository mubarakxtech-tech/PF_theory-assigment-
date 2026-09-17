
#include <stdio.h>
#include <ctype.h>
 
int main(void)
{
    char vehicle_type, membership, disabled_status, station_avail;
    float batt_level = 0.0, req_level = 0.0;
    float park_hours = 0.0, current_time = 0.0;
    float units = 0.0, deficit = 0.0;
 
    float charge_rate = 0.0, charge_discount_pct = 0.0;
    float charge_subtotal = 0.0, charge_discount_amt = 0.0, charging_cost = 0.0;
    float park_fee = 0.0, final_payable = 0.0;
 
    int priority = 0;         
    int is_peak = 0;
    int charging_allowed = 1;
 
    const char *charging_status = "Charging approved.";
    const char *duration_msg    = "Standard parking duration.";
    printf("Enter the vehicle type (E for Electric, H for Hybrid): ");
    scanf(" %c", &vehicle_type);
    vehicle_type = toupper((unsigned char) vehicle_type);
    while (vehicle_type != 'E' && vehicle_type != 'H') {
        printf("Invalid vehicle type. Please enter E or H: ");
        scanf(" %c", &vehicle_type);
        vehicle_type = toupper((unsigned char) vehicle_type);
    }
 
    printf("Enter current battery charge level (0-100): ");
    scanf("%f", &batt_level);
    while (batt_level < 0.0 || batt_level > 100.0) {
        printf("Invalid. Enter a value between 0 and 100: ");
        scanf("%f", &batt_level);
    }
 
    printf("Enter required charging level (0-100): ");
    scanf("%f", &req_level);
    while (req_level < 0.0 || req_level > 100.0) {
        printf("Invalid. Enter a value between 0 and 100: ");
        scanf("%f", &req_level);
    }
 
    printf("Enter expected parking duration in hours: ");
    scanf("%f", &park_hours);
    while (park_hours < 0.0) {
        printf("Invalid. Duration cannot be negative: ");
        scanf("%f", &park_hours);
    }
 
    printf("Enter current time in 24-hour format (0 - 23.99): ");
    scanf("%f", &current_time);
    while (current_time < 0.0 || current_time >= 24.0) {
        printf("Invalid. Enter a time from 0 to 23.99: ");
        scanf("%f", &current_time);
    }
 
    printf("Do you have a parking membership? (Y/N): ");
    scanf(" %c", &membership);
        membership = toupper((unsigned char) membership);
    while (membership != 'Y' && membership != 'N') {
        printf("Invalid. Please enter Y or N: ");
        scanf(" %c", &membership);
        membership = toupper((unsigned char) membership);
    }
 
    printf("Do you have disabled-person priority status? (Y/N): ");
    scanf(" %c", &disabled_status);
    disabled_status = toupper((unsigned char) disabled_status);
    while (disabled_status != 'Y' && disabled_status != 'N') {
        printf("Invalid. Please enter Y or N: ");
        scanf(" %c", &disabled_status);
        disabled_status = toupper((unsigned char) disabled_status);
    }
 
    printf("Is the charging station currently available? (Y/N): ");
    scanf(" %c", &station_avail);
    station_avail = toupper((unsigned char) station_avail);
    while (station_avail != 'Y' && station_avail != 'N') {
        printf("Invalid. Please enter Y or N: ");
        scanf(" %c", &station_avail);
        station_avail = toupper((unsigned char) station_avail);
    }
    is_peak = (current_time >= 17.0f && current_time < 22.0f);

    if (station_avail == 'N') {
        charging_allowed = 0;
        if (vehicle_type == 'H')
            charging_status = "Charging unavailable - Parking only.";
        else
            charging_status = "No charging slot available.";
    }

    if (charging_allowed) {
        if (vehicle_type == 'H' && batt_level >= 40.0f) {
            charging_allowed = 0;
            charging_status = "Vehicle does not qualify for EV charging.";
        }
    }
 
    if (charging_allowed) {
        deficit = req_level - batt_level;
        if (deficit <= 0.0f) {
            deficit = 0.0f;
            charging_allowed = 0;
            charging_status = "No charging required.";
        }
    }
 
    if (charging_allowed) {
        printf("Enter the number of charging units consumed: ");
        scanf("%f", &units);
        while (units < 0.0f) {
            printf("Invalid. Units cannot be negative: ");
            scanf("%f", &units);
        }
 
        if (batt_level <= 15.0f && req_level >= 80.0f) {
            priority = 1;
        } else if (disabled_status == 'Y' ||
                   (membership == 'Y' && batt_level <= 30.0f)) {
            priority = 2;
        } else {
            priority = 3;
        }
 
        if (is_peak) {
            charge_rate = 50.0f;
            charge_discount_pct = 10.0f;
        } else {
            charge_rate = 35.0f;
            if (membership == 'Y')
                charge_discount_pct = 20.0f;
            else
                charge_discount_pct = 0.0f;
        }
 
        if (priority == 1 && !is_peak) {
            charge_discount_pct = 0.0f;
        }
 
        charge_subtotal     = units * charge_rate;
        charge_discount_amt = charge_subtotal * (charge_discount_pct / 100.0f);
        charging_cost       = charge_subtotal - charge_discount_amt;
    }
 
    if (park_hours > 8.0f)
        duration_msg = "Long-stay warning: Please relocate your vehicle after charging.";
    else
        duration_msg = "Standard parking duration.";
 
    
    if (disabled_status == 'Y') {
        park_fee = 0.0f;                      
    } else {
        if (park_hours <= 2.0f)
            park_fee = 200.0f;
        else if (park_hours <= 5.0f)
            park_fee = 400.0f;
        else
            park_fee = 700.0f;
 
        if (membership == 'Y')
            park_fee -= park_fee * 0.20f;     
    }
 
    final_payable = charging_cost + park_fee;
 
    
    printf("\n=================== SYSTEM SUMMARY REPORT ===================\n");
    printf("Vehicle Type               : %c (%s)\n",
           vehicle_type, vehicle_type == 'E' ? "Electric" : "Hybrid");  
    printf("Current Battery Percentage : %.2f%%\n", batt_level);
    printf("Required Charging Level    : %.2f%%\n", req_level);
    printf("Required Charging Deficit  : %.2f%%\n", deficit);
 
    if (priority == 0)
        printf("Charging Priority Level    : Not applicable\n");
    else if (priority == 1)
        printf("Charging Priority Level    : Priority 1 - Emergency Charging\n");
    else if (priority == 2)
        printf("Charging Priority Level    : Priority 2 - Priority Charging\n");
    else
        printf("Charging Priority Level    : Priority 3 - Normal Charging\n");
 
    printf("Peak / Off-Peak Status     : %s\n",
           is_peak ? "Peak (Rs. 50/unit)" : "Off-Peak (Rs. 35/unit)");
    printf("Charging Units Consumed    : %.2f\n", units);
    printf("Charging Discount Applied  : Rs. %.2f (%.0f%%)\n",
           charge_discount_amt, charge_discount_pct);
    printf("Charging Cost              : Rs. %.2f\n", charging_cost);
    printf("Parking Cost               : Rs. %.2f\n", park_fee);
    printf("Final Payable Amount       : Rs. %.2f\n", final_payable);
    printf("Charging Status            : %s\n", charging_status);
    printf("Parking Duration Status    : %s\n", duration_msg);
    printf("=============================================================\n");
 
    return 0;
}
 
