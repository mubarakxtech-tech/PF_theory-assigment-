# PF_theory-assigment-
PF theory first assignment  , divided into two parts A (algorithm , pseudocode) and part b (ipo ,pac, algorithm ,flowchart ,C code)
# C Programming Assignments - System Design & Documentation

Welcome to the repository! This project contains modular C programs along with their system design documentation, featuring explicit Problem Analysis Charts (PAC) and Input-Process-Output (IPO) tables.

---

## 📑 Master Table of Contents

| Program # | Program Name | Source File Name | Documentation Section |
| :---: | :--- | :--- | :--- |
| **1** | Hotel Booking System | `hotel_booking.c` | [View Section](#program-1-hotel-booking-system) |
| **2** | Elevator Control System | `elevator_control.c` | [View Section](#program-2-elevator-control-system) |
| **3** | Student Results Processing | `student_results.c` | [View Section](#program-3-student-results-processing-system) |
| **4** | Item Billing & Tax Calculator | `billing_system.c` | [View Section](#program-4-item-billing--tax-calculator) |
| **5** | Campus Parking & EV Charging | `ev_charging_system.c` | [View Section](#program-5-campus-parking--ev-charging-management-system) |

---

## Program-by-Program Documentation

---

### Program 1: Hotel Booking System (`hotel_booking.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total guests ($N$)<br>• Season choice (`1` for peak, `2` for off-peak)<br>• Room type choice (`1` standard, `2` deluxe, `3` suite)<br>• Number of nights stay |
| **Required (Outputs)** | • Final price and discount applied for each guest<br>• Cumulative total revenue for the hotel |
| **Processing & Logic** | • Iterates through $N$ guests using a `while` loop.<br>• Selects base nightly rate via nested conditions based on season and room tier.<br>• Computes base cost ($\text{Rate} \times \text{Nights}$).<br>• Applies a 15% discount if nights $> 7$; otherwise, no discount.<br>• Accumulates each guest's final amount into `hotel_total_revenue`. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • `guests`<br>• `season`<br>• `room_type`<br>• `nights_stay` | 1. Read total guest count ($N$).<br>2. Initialize loop counter and revenue accumulator to 0.<br>3. While counter $\le N$:<br>&nbsp;&nbsp;&nbsp;&nbsp;• Read season, room type, and nights.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Assign base rate via condition checks.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Compute base total cost.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Check if nights $> 7$ for 15% discount.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Accumulate final cost into hotel revenue.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Print individual guest details and increment counter.<br>4. Print final hotel total revenue. | • Individual guest bills (`Rs. ...`)<br>• Discounts applied (`Rs. ...`)<br>• Hotel's Total Revenue (`Rs. ...`) |

---

### Program 2: Elevator Control System (`elevator_control.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total number of floor requests ($i$)<br>• Sequence of requested floors |
| **Required (Outputs)** | • Directional movement messages (moving up/down)<br>• Current floor updates and door opening notices |
| **Processing & Logic** | • Iterates through floor requests sequentially using a decrementing loop.<br>• Compares `requested_floor` with `current_floor`.<br>• Dynamically updates `current_floor` after each request. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • Number of requests (`i`)<br>• `requested_floor` | 1. Read total number of requests.<br>2. Loop $N$ times to accept each `requested_floor`.<br>3. Compare request with `current_floor`:<br>&nbsp;&nbsp;&nbsp;&nbsp;• If greater: Print moving up.<br>&nbsp;&nbsp;&nbsp;&nbsp;• If lesser: Print moving down.<br>&nbsp;&nbsp;&nbsp;&nbsp;• If equal: Print already on floor / open door.<br>4. Update `current_floor = requested_floor`. | • Movement status logs<br>• Door opening notifications |

---

### Program 3: Student Results Processing System (`student_results.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total number of students<br>• Marks for 5 individual subjects per student (out of 100) |
| **Required (Outputs)** | • Total marks and average percentage per student<br>• Failure deficiency counts and academic grading result |
| **Processing & Logic** | • Uses nested `while` loops (outer for students, inner for 5 subjects).<br>• Tracks failed subjects (marks $< 33$).<br>• Evaluates grade categories: Distinction ($\ge 80$), Pass ($\ge 60$), Fail, or Subject Deficiency. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • `students`<br>• Subject `marks` (5 per student) | 1. Read total students.<br>2. Loop through each student:<br>&nbsp;&nbsp;&nbsp;&nbsp;• Inner loop collects 5 subject marks.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Accumulates total sum and counts failures ($<33$).<br>&nbsp;&nbsp;&nbsp;&nbsp;• Calculates average.<br>&nbsp;&nbsp;&nbsp;&nbsp;• Assigns status (Distinction, Pass, Fail).<br>3. Print student summaries. | • Total marks<br>• Average percentage<br>• Result classification (Pass/Fail/Distinction) |

---

### Program 4: Item Billing & Tax Calculator (`billing_system.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Item quantity and price per item<br>• Discount percentage and tax percentage |
| **Required (Outputs)** | • Subtotal, discounted amount, and final total bill<br>• Input validation error messages |
| **Processing & Logic** | • Validates that quantities/prices are positive and percentages are within valid ranges ($0$ to $<100$).<br>• Computes subtotal ($\text{quantity} \times \text{price}$).<br>• Applies discount deduction, then adds applicable tax. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • `quantity`<br>• `price_per_item`<br>• `discount_per`<br>• `tax_per` | 1. Prompt and read inputs.<br>2. Validate input ranges; terminate with error if invalid.<br>3. Calculate subtotal.<br>4. Compute discounted amount.<br>5. Calculate final bill with tax addition. | • Subtotal value<br>• Discounted amount<br>• Final bill total |

---

### Program 5: Campus Parking & EV Charging Management System (`ev_charging_system.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Vehicle type (`E`, `H`), battery levels, and charging deficit<br>• Parking hours and time of day (24-hr format)<br>• Membership, disabled status, and station availability |
| **Required (Outputs)** | • Charging qualification status and priority level (P1–P3)<br>• Peak/off-peak rates, itemized costs, and discounts<br>• Final payable amount and long-stay warnings |
| **Processing & Logic** | • Validates inputs and enforces powertrain/battery eligibility.<br>• Assigns priority tiers (Emergency, Priority, Normal).<br>• Computes peak (Rs. 50) vs off-peak (Rs. 35) electricity charges.<br>• Calculates tiered parking fees with member/disabled exemptions. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • Powertrain, battery, & time data<br>• User status flags & parking duration | 1. Validate inputs and check station/battery qualification.<br>2. Determine charging deficit and priority category.<br>3. Check peak status and compute electricity costs.<br>4. Calculate parking fees and apply exemptions/discounts.<br>5. Generate comprehensive summary report. | • Charging & parking cost breakdowns<br>• Applied discounts & final payable amount<br>• Status messages & warnings |

