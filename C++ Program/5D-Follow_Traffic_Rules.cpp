#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, v;
    cin >> a >> v;
    int l, d, w;
    cin >> l >> d >> w;

    double acceleration_time = static_cast<double>(w) / a;
    double time_at_max_speed = static_cast<double>(l - d) / w;
    double deceleration_time = static_cast<double>(w) / a;

    double total_time = acceleration_time + time_at_max_speed + deceleration_time;

    cout << fixed << setprecision(5) << total_time << endl;

    return 0;
}
//Worng code plz help