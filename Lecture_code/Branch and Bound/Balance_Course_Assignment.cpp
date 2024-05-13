#include<bits/stdc++.h>
using namespace std;

// Các biến toàn cục
int num_Teachers, num_Courses;
int weight_max = INT_MAX; // Tải trọng lớn nhất của giáo viên mà chúng ta cố gắng tối thiểu hóa
vector<int> weight_teacher; // Mảng để lưu trữ số lượng khóa học đã được gán cho mỗi giáo viên
vector<vector<int>> confict_course(35); // Danh sách kề của các khóa học xung đột
vector<vector<int>> teacher_course(35); // Các khóa học hiện đã gán cho mỗi giáo viên
vector<vector<int>> course_teacher(35); // Các giáo viên có thể dạy mỗi khóa học

// Hàm kiểm tra xem có thể gán khóa học cho giáo viên mà không xảy ra xung đột
bool check(int teacher, int course){
    // Ngăn không cho gán quá tải cho giáo viên so với tải trọng tối đa tối thiểu hiện tại
    if(weight_teacher[teacher] + 1 > weight_max) return false;
    
    // Kiểm tra xung đột với các khóa học đã được gán cho giáo viên này
    for(int courses_isSelected : teacher_course[teacher]){
        for(int course_conflict : confict_course[course]){
            if(course_conflict == courses_isSelected) return false;
        }
    }

    return true;
}

// Hàm đệ quy để thử gán khóa học cho giáo viên
void Try(int course){
    if(course > num_Courses){
        // Tính tải trọng tối đa giữa các giáo viên
        int weight_max_curr = *max_element(weight_teacher.begin(), weight_teacher.end());
        // Cập nhật tải trọng tối đa tối thiểu toàn cục
        weight_max = min(weight_max, weight_max_curr);
        return;
    }

    // Thử gán khóa học này cho mỗi giáo viên có thể
    for(int teacher : course_teacher[course]){
        if(check(teacher, course)){
            // Gán khóa học cho giáo viên và tăng tải trọng
            weight_teacher[teacher]++;
            teacher_course[teacher].push_back(course);
            
            // Đệ quy thử gán khóa học tiếp theo
            Try(course + 1);
            
            // Quay lui: bỏ khóa học và giảm tải trọng
            weight_teacher[teacher]--;
            teacher_course[teacher].pop_back();
        }
    }
}

int main(){
    // Nhập số lượng giáo viên và khóa học
    cin >> num_Teachers >> num_Courses;
    weight_teacher.resize(num_Teachers + 1, 0);

    // Đọc danh sách khóa học mỗi giáo viên có thể dạy
    for(int i=1; i <= num_Teachers; ++i){
        int idx_course_teacher, course;
        cin >> idx_course_teacher;
        while(idx_course_teacher--){
            cin >> course;
            course_teacher[course].push_back(i);
        }
    }

    // Đọc danh sách các khóa học xung đột
    int num_conflict;
    cin >> num_conflict;
    while(num_conflict--){
        int course1, course2;
        cin >> course1 >> course2;
        confict_course[course1].push_back(course2);
        confict_course[course2].push_back(course1);
    }

    // Bắt đầu quá trình thử gán khóa học
    Try(1);

    // Xuất ra tải trọng tối đa tối thiểu tìm được, hoặc -1 nếu không tìm được giải pháp
    cout << (weight_max == INT_MAX ? -1 : weight_max);
    return 0;
}
