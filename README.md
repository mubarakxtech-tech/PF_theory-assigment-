# C Programming Assignments - System Design & Documentation

Welcome to the repository! This project contains modular C programs along with their system design documentation, featuring explicit Problem Analysis Charts (PAC) and Input-Process-Output (IPO) tables.

---

## 📑 Master Table of Contents

| Program # | Program Name | Source File Name | Documentation Section |
| :---: | :--- | :--- | :--- |
| **1** | Hotel Booking System | `q1.c` | [View Section](#program-1-hotel-booking-system) |
| **2** | Elevator Control System | `q2.c` | [View Section](#program-2-elevator-control-system) |
| **3** | Student Results Processing | `q3.c` | [View Section](#program-3-student-results-processing-system) |
| **4** | Item Billing & Tax Calculator | `q4.c` | [View Section](#program-4-item-billing--tax-calculator) |
| **5** | Campus Parking Management System | `q5.c` | [View Section](#program-5-campus-parking-management-system) |
| **6** | Campus Parking & EV Charging System | `q6.c` | [View Section](#program-6-campus-parking--ev-charging-system) |

---

## Program-by-Program Documentation

---

### Program 1: Hotel Booking System (`q1.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total guests ($N$)<br>• Season choice (`1` peak, `2` off-peak)<br>• Room type (`1` standard, `2` deluxe, `3` suite)<br>• Number of nights stay |
| **Required (Outputs)** | • Final price and discount applied for each guest<br>• Cumulative total revenue for the hotel |
| **Processing & Logic** | • Iterates through guests using a loop.<br>• Assigns base nightly rates using nested conditions.<br>• Applies a 15% discount if stay duration $> 7$ nights.<br>• Accumulates total hotel revenue. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • `guests`, `season`, `room_type`, `nights_stay` | 1. Read guest count and initialize variables.<br>2. Loop through each guest to read preferences.<br>3. Calculate base cost, check discounts, and accumulate revenue. | • Individual guest bills<br>• Discounts applied<br>• Hotel Total Revenue |

---

### Program 2: Elevator Control System (`q2.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total number of floor requests<br>• Sequence of requested floors |
| **Required (Outputs)** | • Directional movement logs (moving up/down)<br>• Door opening notices and current floor updates |
| **Processing & Logic** | • Iterates sequentially through requests.<br>• Compares requested floor with current floor to determine direction.<br>• Updates current floor status dynamically. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • Number of requests, `requested_floor` | 1. Accept request count.<br>2. Loop through requests and compare with current floor.<br>3. Print movement status and update floor tracker. | • Movement logs<br>• Door notifications |

---

### Program 3: Student Results Processing System (`q3.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total number of students<br>• Marks for 5 subjects per student |
| **Required (Outputs)** | • Total marks and average percentage<br>• Failure deficiency counts and academic status |
| **Processing & Logic** | • Uses nested loops for students and subjects.<br>• Tracks failed subjects ($<33$ marks).<br>• Evaluates grade classifications (Distinction $\ge 80$, Pass $\ge 60$, Fail). |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • Student count, Subject `marks` | 1. Read student count.<br>2. Collect 5 subject marks per student.<br>3. Calculate totals, averages, and check pass/fail criteria. | • Total marks, average percentage, and final status |

---

### Program 4: Item Billing & Tax Calculator (`q4.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Item quantity and unit price<br>• Discount percentage and tax percentage |
| **Required (Outputs)** | • Subtotal, discount amount, and final total bill<br>• Input validation error messages |
| **Processing & Logic** | • Validates positive values and valid percentage ranges.<br>• Computes subtotal, applies discount, and adds applicable tax. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • `quantity`, `price_per_item`, `discount_per`, `tax_per` | 1. Read and validate inputs.<br>2. Compute subtotal.<br>3. Calculate discount deduction and tax addition. | • Subtotal value<br>• Discounted amount<br>• Final bill total |

---

### Program 5: Campus Parking Management System (`q5.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Total vehicles to process<br>• Vehicle type (`C`, `B`, `V`)<br>• User category (`F` Faculty, `S` Student, `G` Visitor)<br>• Permit status (`Y`/`N`) and Emergency status (`Y`/`N`) |
| **Required (Outputs)** | • Acceptance/rejection status logs<br>• Zone occupancy counts and remaining capacities<br>• Summary report with highest occupancy zone and campus full status |
| **Processing & Logic** | • Validates inputs and rejects vehicles without permits unless they are emergency vehicles.<br>• Assigns space requirements (Vans take 2 spaces, Cars/Bikes take 1).<br>• Allocates zones based on user category (Zone A for Faculty, Zone B/C for Students, Zone C for Visitors) and checks available capacity.<br>• Tracks total accepted/rejected counts and evaluates peak zone occupancy. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • `total_processed`<br>• `vehicle_type`<br>• `user_category`<br>• `permit_status`<br>• `emergency_status` | 1. Read total vehicles to process.<br>2. Loop through each vehicle: validate inputs and permit/emergency status.<br>3. Determine required spaces and check zone availability based on user category.<br>4. Update zone occupancy and log success/rejection.<br>5. Generate final summary report, calculate highest occupancy zone, and check if campus is full. | • Acceptance/rejection messages<br>• Remaining zone capacities<br>• Comprehensive campus summary report |

---

### Program 6: Campus Parking & EV Charging System (`q6.c`)

#### PAC Chart (Problem Analysis Chart)
| Category | Description |
| :--- | :--- |
| **Given (Inputs)** | • Vehicle type (`E` Electric, `H` Hybrid)<br>• Battery charge level & required charging level (0–100)<br>• Parking hours & current time (24-hr format)<br>• Membership, disabled status, and station availability |
| **Required (Outputs)** | • Charging qualification status & priority level (P1–P3)<br>• Peak/off-peak rate status and itemized costs<br>• Final payable amount and long-stay duration warnings |
| **Processing & Logic** | • Validates input ranges and checks station availability/powertrain eligibility.<br>• Computes charging deficit and assigns priority tiers (Priority 1 for emergencies, 2 for disabled/members with low battery, 3 for normal).<br>• Computes peak (Rs. 50) vs off-peak (Rs. 35) rates and applies membership discounts.<br>• Calculates tiered parking fees with exemptions for disabled individuals and member discounts.<br>• Summarizes total costs and generates warning alerts. |

#### IPO Table (Input-Process-Output)
| Inputs | Processing Steps | Outputs |
| :--- | :--- | :--- |
| • Vehicle & battery data<br>• Parking hours & time<br>• User status flags | 1. Prompt and validate user inputs.<br>2. Check station availability and hybrid/electric charging eligibility.<br>3. Compute deficit, assign priority tier, and determine peak/off-peak rates.<br>4. Calculate charging costs with applicable discounts.<br>5. Compute parking fees based on duration and exemptions.<br>6. Output comprehensive system summary report. | • Itemized charging & parking costs<br>• Applied discounts & final payable amount<br>• System summary report & warnings |