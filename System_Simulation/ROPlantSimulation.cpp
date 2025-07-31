#include <iostream>
using namespace std;

int main() {
    int ot_level, rt_level; // water levels in %

    // Prompt the user for input
    cout << "Enter Overhead Tank (OT) Level (0, 25, 50, 75, 100): ";
    cin >> ot_level;

    cout << "Enter RO Tank (RT) Level (0, 25, 50, 75, 100): ";
    cin >> rt_level;

    // Validate input
    if ((ot_level % 25 != 0 || ot_level < 0 || ot_level > 100) ||
        (rt_level % 25 != 0 || rt_level < 0 || rt_level > 100)) {
        cout << "❌ Invalid input! Levels must be 0, 25, 50, 75, or 100." << endl;
        return 1;
    }

    // Simulated actuator states
    bool valve = false;
    bool motor1 = false;
    bool motor2 = false;

    // Display levels
    cout << "\n📊 Status Summary:" << endl;
    cout << "OT Level: " << ot_level << "%" << endl;
    cout << "RT Level: " << rt_level << "%" << endl;

    // Control logic
    if (ot_level >= 25) {
        if (rt_level <= 50) {
            valve = true;
            motor1 = true;
            motor2 = true;
            cout << "✅ System ON: Valve + Motor1 + Motor2 started" << endl;
        } else if (rt_level == 100) {
            valve = false;
            motor1 = false;
            motor2 = false;
            cout << "⚠️ RO Tank Full: System stopped" << endl;
        }
    } else {
        valve = false;
        motor1 = false;
        motor2 = false;
        cout << "🚫 OT Tank Empty: System OFF" << endl;
    }

    // Final status
    cout << "\n🔌 Output Status:" << endl;
    cout << "Valve Status: " << (valve ? "ON" : "OFF") << endl;
    cout << "Motor1 Status: " << (motor1 ? "ON" : "OFF") << endl;
    cout << "Motor2 Status: " << (motor2 ? "ON" : "OFF") << endl;

    return 0;
}
