# RO Plant Automation 🚰

This project demonstrates the automation of a Reverse Osmosis (RO) water plant using two approaches:

1. 🛠️ **Arduino-based automation** with relays, sensors, and an LCD  
2. 💻 **C++ simulation** that runs in the terminal (for systems without hardware)

---

## 📁 Project Structure

RO-Plant-Automation/  
├── Arduino_Code/  
│ └── ROPlantAutomation.ino  
├── System_Simulation/  
│ └── ROPlantSimulation.cpp  
└── README.md

---

## 🔌 Arduino Version (`Arduino_Code/ROPlantAutomation.ino`)

- Uses 8 float sensors (4 for Overhead Tank, 4 for RO Tank)  
- Controls 2 motors and 1 solenoid valve via relays  
- Displays tank water levels on a 16x2 LCD  
- Implements protection against overflow and dry run

### 🛠 Hardware Used  
- Arduino Uno  
- Float sensors (x8)  
- Relay Module (x3)  
- 16x2 LCD (with potentiometer)  
- Solenoid Valve  
- Motors (or water pumps)

---

## 💻 C++ Simulation (`System_Simulation/ROPlantSimulation.cpp`)

- Takes OT and RT tank levels as input (0%, 25%, 50%, 75%, 100%)  
- Simulates control logic for valve and motors  
- Displays decision output in terminal  
- Works without any hardware — for learning or demo use

### 💬 Example Output

Enter Overhead Tank (OT) Level (0, 25, 50, 75, 100): 50
Enter RO Tank (RT) Level (0, 25, 50, 75, 100): 25
✅ System ON: Valve + Motor1 + Motor2 started


---

## 📦 How to Use

### Arduino:  
1. Open `ROPlantAutomation.ino` in **Arduino IDE**  
2. Connect sensors, relays, and LCD as per the code pin mapping  
3. Upload the sketch to your Arduino Uno  
4. Monitor LCD and relay behavior based on tank levels

### C++ Simulation:

```bash
g++ ROPlantSimulation.cpp -o ROPlantSimulation  
./ROPlantSimulation

Enter tank levels when prompted and view system logic decisions in terminal


---

**After replacing your README.md with this, run these commands:**

```bash
git add README.md
git commit -m "Resolved merge conflict in README.md"
git push -u origin main

