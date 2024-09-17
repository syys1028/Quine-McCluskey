#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <algorithm>

class CLA {                                     // CLASS CLA 선언
public:
    // ************* 전역변수 ************* //

    // 2진수로 이루어진 십진테이블
    char table_2_arr[16][5] = { {'0','0','0','0','0'}, {'0','0','0','1','0'}, {'0','0','1','0','0'}, {'0','0','1','1','0'}, // 0 1 2 3
             {'0','1','0','0','0'}, {'0','1','0','1','0'}, {'0','1','1','0','0'}, {'0','1','1','1','0'},             // 4 5 6 7
             {'1','0','0','0','0'}, {'1','0','0','1','0'}, {'1','0','1','0','0'}, {'1','0','1','1','0'},             // 8 9 10 11
             {'1','1','0','0','0'}, {'1','1','0','1','0'}, {'1','1','1','0','0'}, {'1','1','1','1','0'} };           // 12 13 14 15 

    // 선택된 최소항 배열 (num 배열은 10진수 숫자, char 배열은 구조가 들어있으며, num 배열은 -1, char 배열은 a로 초기화
    int first_prime_key_num[30][2];             // 첫 번째 최소항 비교에서 사용되는 배열 (10진수 숫자, 초기상태 -1)
    char first_prime_key_char[30][4];           // 첫 번째 최소항 비교에서 사용되는 배열 (구조, 초기상태 'a')

    int second_prime_key_num[30][4];            // 두 번째 최소항 비교에서 사용되는 배열 (10진수 숫자, 초기상태 -1)
    char second_prime_key_char[30][4];          // 두 번째 최소항 비교에서 사용되는 배열 (구조, 초기상태 'a')
    int key_index, key_index2;                  // first_num 배열과 second_num 배열의 index 값 (해당되는 값만 배열에 추가하기 위해 필요)

    int essential_pi_num[16][4];                // 최종 PI 키 배열 (10진수 숫자, 초기상태 -1)
    char essential_pi_char[16][4];              // 최종 PI 키 배열 (구조, 초기상태 'a')
    int pi_index = 0;                           // essential_num 배열의 index 값

    int repeat_num[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // second_num 배열에서 중복된 값을 제거하기 위한 배열
    int repeat_key = 0;                         // repeat_num 배열의 index 값

    // 인덱스 배열
    int arr[16] = { -1, };                      // table_arr 1의 개수 배열 (배열의 값:2진수에서 1의 개수, 0:초기상태, -1:선택되지않음, 1이상:선택됨)
    int arr2[30] = { -1, };                     // first_num 1의 개수 배열 (배열의 값:2진수에서 1의 개수, 0:초기상태, -1:선택되지않음, 1이상:선택됨) 
    int array_x[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // 테이블 표에서 각 최소항의 행 출력배열 (0:해당 최소항에 없음, -1:전체 최소항에 없음, 1:해당값, 2:최종 pi키, 3:사라진 키) 

    int table_array_row[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // 테이블 표에서 존재하는 전체 숫자 배열 (행)
    int table_array_col[30][4];                 // 테이블 표에서 존재하는 전체 최소항 배열 (열)

    // ************* 함수 호출 *************
    void manage();                              // 기본 호출 함수
    void f1_input_num();                        // 함수1 : 숫자 선택하기
    void f2_grouping1();                        // 함수2 : 1단계 - 1의 개수로 그룹핑
    void f3_checkBit_1();                       // 함수3 : 1단계 - 1의 개수 체크
    void f4_grouping2();                        // 함수4 : 2단계 - 1의 개수로 그룹핑
    void f5_checkBit_2();                       // 함수5 : 2단계 - 1의 개수 체크
    void f6_select_prime_key();                 // 함수6 : prime 키 선택하기
    void f7_prime_table();                      // 함수7 : 테이블 표 작성
    void f8_essential_key();                    // 함수8 : 추가 epi 추출 후 테이블 표 재작성
    void f9_final_expression();                 // 함수9 : 최종 epi 선정 후 논리식 출력

    void resetArray();                          // 배열 초기화 함수 (first 배열)
    void resetArray2();                         // 배열 초기화 함수 (second 배열)
    void resetArray3();                         // 배열 초기화 함수 (essential 배열)

    void compareBit(int index1, int index2);    // 첫 번째 인접세션 비교 후 출력 함수
    void compareBit2(int index1, int index2);   // 두 번째 인접세션 비교 후 출력 함수
    void sortArray(int arr[][4], int rows);     // 2차원 배열 정렬 함수
    void select_table_row();                    // table_row 배열 요소 추출
    void select_pi_key(int x);                  // 첫 번째 epi 키 삽입 함수
    void select_pi_key_2(int x);                // 추가 epi 키 삽입 함수
    void change_alpha(int x);                   // 최소항 구조의 기호를 논리식으로 변경하는 함수

    void removeRepeat();                        // second 배열 반복 제거 함수
    void removeDouble(int x);                   // essential 배열 반복 제거 함수

    void print_all_table();                     // 2진수 십진 테이블 표 출력 함수
    void print_group_table(int counts);         // 첫 번째 1의 개수 그룹핑 표 출력 함수 (table_arr에서 추출)
    void print_group_table2(int counts);        // 두 번째 1의 개수 그룹핑 표 출력 함수 (first_num에서 추출)
    void print_final_key();                     // 선별된 최소항 출력 함수 (second_num에서 추출)
    void print_prime_table(int temp);           // 테이블 표 출력 함수 (temp 0:기본, 1:epi추출, 2:추가epi추출)
    void print_table_basic(int x);              // 테이블 표 기본 0과 1 출력 함수
    void print_table_x(int x);                  // 첫 번째 테이블 표 출력 함수
    void print_table_x2(int x);                 // 두 번째 테이블 표 출력 함수 (첫 번째 epi 선택)
    void print_table_x3(int x);                 // 최종 테이블 표 출력 함수 (추가 epi 선택)
    void print_table_space(int x);              // 테이블 표에서 자리수에 따른 공백 출력 함수

    int next_skip();                            // 다음 화면으로 넘어가는 함수
};

using namespace std;

int main() {                                    // 메인 함수
    CLA nm;                                     // 클래스 선언
    nm.manage();                                // 기본 함수 호출
    return 0;
}

void CLA::manage() {                            // 기본 호출 함수
    f1_input_num();                             // 함수1 호출
}

// ************* 단계별 함수 *************
void CLA::f1_input_num() {                             // 함수1 : 숫자 선택하기
    int input = 0;
    cout << endl << "  < 최소항으로 사용할 숫자 선택 > (1:사용, 0 :사용안함)" << endl;
    cout << endl << "      A | B | C | D | X " << endl;
    cout << " -----------------------" << endl;
    for (int i = 0; i < 16; i++) {
        if (i >= 10) cout << " (" << i << ")";          // 자리수에 따른 10진수 출력
        else cout << " (" << i << ") ";
        cout << " ";
        for (int j = 0; j < 5; j++) {                   // 2진수 출력
            if (j != 4) {                               // 자리수에 따라 마지막을 제외하고 | 출력
                cout << table_2_arr[i][j];
                if (j < 4) cout << " | ";
            }
            else {
                cin >> input;                               // j가 4이면 숫자 입력받기
                if (input == 1) table_2_arr[i][4] = '1';    // 1이면 선택
                else table_2_arr[i][4] = '0';               // 그외는 전부 0
            }
        }
    }
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {                                 // 스페이스 바를 클릭하면 다음 함수로 넘어감
        system("cls");
        cout << endl << endl << "  < 완성된 이진수 테이블 >" << endl;
        print_all_table();                                  // 선택된 2진수 십진 테이블 표 출력
    }
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        f2_grouping1();                                     // 함수2 호출
    }
}

void CLA::f2_grouping1() {                                  // 함수2 : 1단계 - 1의 개수로 그룹핑
    int count = 0;
    for (int i = 0; i < 16; i++) {
        count = 0;
        if (table_2_arr[i][4] == '1') {                     // table_arr에서 선택한 숫자만 골라서
            for (int j = 0; j < 4; j++) {
                if (table_2_arr[i][j] == '1')               // 1의 개수를 count에 저장
                    count += 1;
            }
            arr[i] = count;                                 // arr배열의 인덱스에 1의 개수 저장 
        }
        else arr[i] = -1;                                   // 선택되지 않았다면 -1 저장
    }
    cout << endl << "  < 1단계 >" << endl << "  < 1의 개수로 그룹핑 >" << endl;
    cout << endl << "    | A | B | C | D " << endl;
    cout << " -------------------" << endl;
    for (int i = 0; i < 5; i++) {                           // 1의 개수 0부터 4까지
        print_group_table(i);                               // 그룹핑 표 출력
        cout << " -------------------" << endl;
    }
    f3_checkBit_1();                                    // 함수3 이어서 호출
}

void CLA::f3_checkBit_1() {                             // 함수3 : 1단계 - 1의 개수 체크
    int trap = 0, i = 0, j = 0;                         // trap : 1의 개수
    int index_1 = -1, index_2 = -1;
    key_index = 0;                                      // first_num의 인덱스 값 초기화
    cout << endl << endl << "  < 인접세션 비교 #1 >" << endl;
    resetArray();                                       // first 배열 초기화
    cout << endl << "  A | B | C | D " << endl;
    cout << " ---------------" << endl;
    if (arr[0] != 0) trap += 1;                         // 0이 선택되지 않았다면 (0의 1의개수 0이 입력되지 않았다면) trap = 1부터 시작
    while (trap < 5) {                                  // trap이 4일 때까지 반복
        for (i = 0; i < 16; i++) {
            if (arr[i] == trap && arr[i] != -1)         // 선택되고 1의 개수가 trap과 같다면
                if (index_1 < i) {                      // index1에 저장된 숫자보다 현재 i가 클 때 (비교하지 않은 항 일때),
                    index_1 = i;                        // 현재 i(인덱스)를 index1에 저장 후 멈춤
                    break;
                }
        }
        if (index_1 == -1) trap += 1;
        if (index_1 != -1 && i != 16) {                                      // i가 중간에 멈췄다면
            for (j = 0; j < 16; j++) {
                if (arr[j] == trap + 1 && arr[j] != -1) {   // 인접세션(trap + 1)에서 선택되고 1의 개수가 trap+1과 같다면
                    index_2 = j;                            // index2에 저장 후
                    compareBit(index_1, index_2);           // 비교 함수 실행 (전부 실행할 때까지 반복)
                }
            }
        }
        else if (i == 16 && j == 16) {                      // 인접세션 비교를 전부 끝마쳤다면
            trap += 1;                                      // 다음 trap으로 이동 후, index 초기화
            index_1 = -1;
            index_2 = -1;
            if (trap == 4) break;                           // 만약 trap+1이 4에 도달했다면 반복 종료
        }
        if (index_1 != -1 && index_2 != -1) cout << " ---------------" << endl;
    }
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        f4_grouping2();                                     // 함수4 호출
    }
}

void CLA::f4_grouping2() {                              // 함수4 : 2단계 - 1의 개수로 그룹핑
    cout << endl << "  < 2단계 >" << endl << "  < 1의 개수로 그룹핑 #2 >" << endl;
    int count = 0;
    for (int i = 0; i < 30; i++) {
        if (i <= key_index) {                           // first 배열의 인덱스를 넘지 않을 경우
            count = 0;
            for (int j = 0; j < 4; j++) {
                if (first_prime_key_char[i][j] == '1')  // first_char에서 선택한 숫자만 골라서
                    count += 1;                         // 1의 개수를 count에 저장
            }
            arr2[i] = count;                            // arr2배열의 인덱스에 1의 개수 저장 
        }
        else arr2[i] = -1;                              // 선택되지 않았다면 -1 저장
    }
    cout << endl << "      A | B | C | D " << endl;
    cout << " -------------------" << endl;

    for (int i = 0; i < 4; i++) {                       // 1의 개수 0부터 4까지
        print_group_table2(i);                          // 그룹핑 표 출력
        cout << " -------------------" << endl;
    }
    f5_checkBit_2();                                     // 함수5 이어서 호출
}

void CLA::f5_checkBit_2() {                                     // 함수5 : 2단계 - 1의 개수 체크
    int trap = 0, i = 0, j = 0, index_1 = -1, index_2 = -1;     // trap : 1의 개수
    key_index2 = 0;                                             // second_num의 인덱스 값 초기화
    cout << endl << endl << "  < 인접세션 비교 #2 >" << endl;
    resetArray2();                                              // second_prime_key 초기화
    cout << endl << "  A | B | C | D " << endl << " ---------------" << endl;
    if (arr2[0] != 0) trap += 1;                                // 0이 선택되지 않았다면 (0의 1의개수 0이 입력되지 않았다면) trap = 1부터 시작
    while (trap < 5) {                                          // trap이 4일 때까지 반복
        for (i = 0; i < 30; i++) {
            if (arr2[i] == trap && arr2[i] != -1)               // 선택되고 1의 개수가 trap과 같다면
                if (index_1 < i) {                              // index1에 저장된 숫자보다 현재 i가 클 때 (비교하지 않은 항 일때),
                    index_1 = i;                                // 현재 i(인덱스)를 index1에 저장 후 멈춤
                    break;
                }
        }
        if (index_1 == -1) trap += 1;
        if (index_1 != -1 && i != 30) {                                           // i가 중간에 멈췄다면
            for (j = 0; j < 30; j++) {
                if (arr2[j] == trap + 1 && arr2[j] != -1) {     // 인접세션(trap + 1)에서 선택되고 1의 개수가 trap+1과 같다면
                    index_2 = j;                                // index2에 저장 후
                    compareBit2(index_1, index_2);              // 비교 함수 실행 (전부 실행할 때까지 반복)
                }
                else {
                    if (index_2 == -1) {
                        if (arr2[j] == trap + 2 && arr2[j] != -1) {     // 인접세션(trap + 2)에서 선택되고 1의 개수가 trap+2과 같다면
                            index_2 = j;                                // index2에 저장 후
                            compareBit2(index_1, index_2);              // 비교 함수 실행 (전부 실행할 때까지 반복)
                        }
                        else {
                            if (arr2[j] == trap + 3 && arr2[j] != -1) {     // 인접세션(trap + 3)에서 선택되고 1의 개수가 trap+3과 같다면
                                index_2 = j;                                // index2에 저장 후
                                compareBit2(index_1, index_2);              // 비교 함수 실행 (전부 실행할 때까지 반복)
                            }
                        }
                    }
                }
            }
        }
        else if (i == 30 && j == 30) {                          // 인접세션 비교를 전부 끝마쳤다면
            trap += 1;                                          // 다음 trap으로 이동 후, index 초기화
            index_1 = -1;
            index_2 = -1;
            if (trap == 4) break;                               // 만약 trap+1이 4에 도달했다면 반복 종료
        }
        if (index_1 != -1 && index_2 != -1) cout << " ---------------" << endl;
    }
    cout << endl;
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        f6_select_prime_key();                                  // 함수6 호출
    }
}

void CLA::f6_select_prime_key() {                               // 함수6 : prime 키 선택하기
    int check_arr[2] = { -1, -1 };                              // 추가할 first num 키 배열
    int index_arr[30] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // second num 키 인덱스 배열 *****************
       -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int check = 0, trap = 0, index = 0;

    while (trap < 30) {                                         // trap(first num의 인덱스)이 30 이하일 때  
        if (first_prime_key_num[trap][0] != -1) {               // 해당 인덱스에 값이 들어있으면
            for (int j = 0; j < 2; j++) {
                check_arr[j] = first_prime_key_num[trap][j];    // check_arr에 넣어서
            }
            for (int i = 0; i < 30; i++) {
                check = 0;
                for (int j = 0; j < 4; j++) {
                    if (check_arr[0] == second_prime_key_num[i][j]) check += 1;         // second_num 배열과 비교하여 같으면 check를 증가
                    else if (check_arr[1] == second_prime_key_num[i][j]) check += 1;
                }
                if (check > 1) {                                // check가 2이상일 때 (숫자쌍이 second_num에 이미 포함되어 있을 때)
                    first_prime_key_num[trap][0] = -1;          // 그 최소항의 시작을 -1로 지정하여 삭제해줌 (중복 방지)
                }
            }
        }
        trap += 1;
    }
    for (int i = 0; i < 30; i++) {
        if (first_prime_key_num[i][0] != -1) {                  // 만약 first_num에서 삭제되지 않은 최소항은 (second_num에 포함되어 있지 않은 경우)
            index_arr[index] = i;                               // index_arr에 first_num 인덱스 값을 넣고 index_arr의 index를 증가
            index += 1;
        }
    }
    removeRepeat();                                             // second 배열 반복 제거 함수 실행
    index = 0;
    trap = 0;
    while (trap != -1) {
        if (index_arr[index] != -1) {                           // index_arr에 값이 존재할 때 (초기값이 아닐 때)
            for (int i = 0; i < 30; i++) {
                if (second_prime_key_num[i][0] == -1) {         // 만약 second_num이 비어있으면
                    second_prime_key_num[i][0] = first_prime_key_num[index_arr[index]][0];  // first_num에서 삭제되지 않은 최소항의 인덱스를 넣고 second_num에 삽입
                    second_prime_key_num[i][1] = first_prime_key_num[index_arr[index]][1];  // first_num은 2개짜리 최소항이니까 0과 1에 넣음
                    for (int j = 2; j < 4; j++) {
                        second_prime_key_num[i][j] = -1;        // 2와 3에는 -1 삽입
                    }
                    for (int j = 0; j < 4; j++) {
                        second_prime_key_char[i][j] = first_prime_key_char[index_arr[index]][j];    // second_char에도 똑같이 해당 인덱스의 구조 넣음
                    }
                    break;
                }
            }
            index += 1;     // index 증가하여 반복
        }
        else {
            trap = -1;
            break;
        }
    }
    cout << endl << endl << "  < 최종 선별된 최소항 >" << endl << endl;
    print_final_key();                                                      // second_num에 저장된 최소항 출력 함수
    cout << endl;
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        f7_prime_table();                                                   // 함수7 호출
    }
}

void CLA::f7_prime_table() {                                                // 함수7 : 테이블 표 작성
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 4; j++) {
            if (second_prime_key_num[i][j] != -1) {                         // second_num에 값이 저장된 경우
                table_array_col[i][j] = second_prime_key_num[i][j];         // table_col(최소항 열)에 옮겨담음
            }
            else table_array_col[i][j] = -1;                                // 없으면 -1 저장
        }
    }
    select_table_row();                                                     // table_row 배열 요소 추출 함수
    cout << endl << endl << "  < 최소항 테이블 >" << endl << endl;
    print_prime_table(0);                                                   // 테이블 표 출력 함수 (0:초기 상태)
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        f8_essential_key();                                                 // 함수 8 호출
    }
}

void CLA::f8_essential_key() {                                              // 함수8 : 추가 epi 추출 후 테이블 표 재작성
    cout << endl << endl << "  < Essential PI 추출 >" << endl << endl;
    resetArray3();                                                          // 배열 초기화 함수 (essential 배열)
    print_prime_table(1);                                                   // 테이블 표 출력 함수 (1:epi추출)
    sort(repeat_num, repeat_num + 16);                                      // second_num의 중복된 숫자를 담은 배열 정렬 
    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        cout << endl << endl << "  < 추가 Essential PI 확인 >" << endl << endl;
        print_prime_table(2);                                               // 테이블 표 출력 함수 (2:추가epi추출)                                               
    }

    cout << endl << "  ...다음으로 넘기려면 스페이스 바를 클릭하세요." << endl;
    if (next_skip() == 1) {
        system("cls");
        f9_final_expression();                                              // 함수 9 호출
    }
}

void CLA::f9_final_expression() {                                           // 함수9 : 최종 epi 선정 후 논리식 출력
    int trap = 0;
    cout << endl << endl << "  < 최종 Essential PI 키와 비트 > " << endl << endl;
    for (int i = 0; i < 16; i++) {
        if (essential_pi_num[i][0] != -1) {                                 // epi_num에 값이 존재하는 경우
            cout << "  ";
            for (int j = 0; j < 4; j++) {
                if (essential_pi_num[i][j] != -1) cout << essential_pi_num[i][j] << " ";    // -1이 아닌 숫자 전부 출력
            }
            cout << ": ";
            for (int j = 0; j < 4; j++) {
                if (essential_pi_char[i][j] != 'a') cout << essential_pi_char[i][j] << " "; // 'a'가 아닌 기호 전부 출력
            }
            cout << endl;
        }
    }
    cout << endl << endl << "  < 최종 논리식 도출 >" << endl << endl;
    cout << "  F = ";
    while (trap != -1) {
        if (essential_pi_num[trap][0] != -1) {                                 // epi_num에 값이 존재하는 경우
            change_alpha(trap);                                                // 논리식으로 변경 함수
            if (trap < 14 && essential_pi_num[trap + 1][0] != -1) cout << " + ";  // + 입력
            trap += 1;
        }
        else {
            trap = -1;
            break;
        }
    }
    cout << endl;
    Sleep(100000);
}
// ************* 기능 함수 *************
// ****** 인접 세션 비교 함수 ******
void CLA::compareBit(int index1, int index2) {                              // 첫 번째 인접세션 비교 후 출력 함수
    int count = 0, check = -1;
    char check_arr[4] = { '-', '-', '-', '-' };
    if (key_index < 30) {                                                   // 키 인덱스가 30을 넘지 않을 경우
        for (int i = 0; i < 4; i++) {
            if (table_2_arr[index1][i] == table_2_arr[index2][i]) {         // table_arr에서 각각의 인덱스와 구조를 비교
                count += 1;                                                 // 같으면 count 증가
                check_arr[i] = table_2_arr[index1][i];                      // 같은 것은 그대로 출력 (다른 건 '-' 상태 그대로)
            }
        }
        cout << "  ";
        for (int i = 0; i < 4; i++) {                                       // 구조 출력
            cout << check_arr[i];
            if (i < 3) cout << " | ";
        }
        if (count == 3) {                                                   // 3개가 같은 경우
            first_prime_key_num[key_index][0] = index1;                     // 2차원 배열 first_num에 해당 인덱스 삽입 
            first_prime_key_num[key_index][1] = index2;
            for (int i = 0; i < 4; i++) {
                first_prime_key_char[key_index][i] = check_arr[i];          // first_char에 구조 삽입
            }
            check = 1;
            key_index += 1;                                                 // key index 증가
        }
        cout << "  (" << index1 << ", " << index2 << ")";
        if (check == 1) {
            cout << "   ◀ ";

        }
        cout << endl;
    }
}

void CLA::compareBit2(int index1, int index2) {                             // 두 번째 인접세션 비교 후 출력 함수
    int count = 0, check = -1;
    char check_arr[4] = { '-', '-', '-', '-' };
    if (key_index2 < 30 && first_prime_key_num[index1][0] != -1) {          // 키 인덱스2가 30을 넘지 않을 경우, first_num에 값이 들어있을 경우
        for (int i = 0; i < 4; i++) {
            if (first_prime_key_char[index1][i] == first_prime_key_char[index2][i]) { // first_char에서 각각의 인덱스와 구조를 비교
                count += 1;                                                 // 같으면 count 증가
                check_arr[i] = first_prime_key_char[index1][i];             // 같은 것은 그대로 출력 (다른 건 '-' 상태 그대로)
            }
        }
        cout << "  ";                                                       // 구조 출력
        for (int i = 0; i < 4; i++) {
            cout << check_arr[i];
            if (i < 3) cout << " | ";
        }
        if (count == 3) {                                                   // 3개가 같은 경우 ('-' 포함)
            second_prime_key_num[key_index2][0] = first_prime_key_num[index1][0];   // 2차원 배열 second_num에 해당 인덱스 삽입 
            second_prime_key_num[key_index2][1] = first_prime_key_num[index1][1];
            second_prime_key_num[key_index2][2] = first_prime_key_num[index2][0];
            second_prime_key_num[key_index2][3] = first_prime_key_num[index2][1];
            for (int i = 0; i < 4; i++) {
                second_prime_key_char[key_index2][i] = check_arr[i];                // second_char에 구조 삽입
            }
            check = 1;
            key_index2 += 1;                                                        // key index 증가
        }
        cout << "  (" << first_prime_key_num[index1][0] << ", " << first_prime_key_num[index1][1];
        cout << ", " << first_prime_key_num[index2][0] << ", " << first_prime_key_num[index2][1] << ")";
        if (check == 1) {
            if (index1 < 10 && index2 < 10) cout << "   ◀ ";
            else if ((index1 < 10 && index2 > 9) || (index1 > 9 && index2 < 10)) cout << "  ◀ ";
            else cout << " ◀ ";
        }
        cout << endl;
    }
}

// ****** 배열 초기화 함수 ******
void CLA::resetArray() {                                // 배열 초기화 함수 (first 배열)
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 2; j++) {
            first_prime_key_num[i][j] = -1;
        }
        for (int j = 0; j < 4; j++) {
            first_prime_key_char[i][j] = 'a';
        }
    }
}

void CLA::resetArray2() {                               // 배열 초기화 함수 (second 배열)
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 4; j++) {
            second_prime_key_num[i][j] = -1;
        }
        for (int j = 0; j < 4; j++) {
            second_prime_key_char[i][j] = 'a';
        }
    }
}

void CLA::resetArray3() {                               // 배열 초기화 함수 (essential 배열)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            essential_pi_num[i][j] = -1;
        }
        for (int j = 0; j < 4; j++) {
            essential_pi_char[i][j] = 'a';
        }
    }
}

// ****** 정렬 함수 ******
void CLA::sortArray(int arr[][4], int rows) {            // 2차원 배열 정렬 함수
    for (int i = 0; i < rows; ++i) {                     // 행 숫자까지 반복
        for (int j = 0; j < 3; ++j) {
            int min = j;                                    // 최소인 min에 j를 입력하고
            for (int k = j + 1; k < 4; ++k) {               // k는 j다음부터 반복
                if (arr[i][k] < arr[i][min]) {              // 만약 min이 k와 같으면
                    min = k;                                // min에 k를 입력
                }
            }
            if (min != j) {                             // min의 값이 변경되면
                swap(arr[i][j], arr[i][min]);           // swap 실행
            }
        }
    }
}

// ****** 반복 제거 함수 ******
void CLA::removeRepeat() {                                              // second 배열 반복 제거 함수
    int check_arr[4] = { -1, -1, -1, -1 };
    int check = 0, trap = 0;
    sortArray(second_prime_key_num, 30);                                // 2차원 정렬 함수를 호출해 second 배열의 숫자들을 오름차순 정렬
    while (trap < 30) {                                                 // trap(second_num의 index)이 30을 넘지 않을 때  *****************
        if (second_prime_key_num[trap][0] != -1) {                      // second 배열에 trap 인덱스 값이 들어있다면
            for (int j = 0; j < 4; j++) {
                check_arr[j] = second_prime_key_num[trap][j];           // 최소항의 숫자들을 check_arr에 넣음
            }
            for (int i = 0; i < 30; i++) {
                check = 0;
                if (trap != i) {                                        // second_num에서 해당 최소항을 뺀 나머지를 반복하며
                    for (int j = 0; j < 4; j++) {
                        if (check_arr[j] == second_prime_key_num[i][j]) // check_arr와 같은 최소항이 있는지 탐색
                            check += 1;
                    }
                    if (check == 4) {                                   // 전부 같으면 
                        second_prime_key_num[i][0] = -1;                // 같은 것은 제거하기
                    }
                }
            }
        }
        trap += 1;
    }
}
void CLA::removeDouble(int x) {                                         // essential 배열 반복 제거 함수
    int check_arr[4] = { -1, -1, -1, -1 };
    int check = 0;
    for (int i = 0; i < 4; i++) {
        check_arr[i] = table_array_col[x][i];                           // 입력받은 인덱스의 최소항 숫자들을 check_arr에 넣음
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (essential_pi_num[i][j] == check_arr[j] && essential_pi_num[i][0] != -1) // epi_num에서 check_arr와 같은 최소항이 있는지 탐색
                check += 1;
        }
        if (check != 4) check = 0;                                      // 전부 같지 않으면 check 초기화 후 반복
        else break;                                                     // 같으면 즉시 멈춤
    }
    if (check != 4) {                                                   // 반복문을 다 돌고도 같은게 없으면
        for (int m = 0; m < 4; m++) {
            essential_pi_num[pi_index][m] = table_array_col[x][m];      // epi_num에 해당 인덱스의 숫자 입력
            essential_pi_char[pi_index][m] = second_prime_key_char[x][m];   // epi_char에도 넣어줌
        }
        pi_index += 1;                                                  // pi 인덱스 증가
    }
}

// ****** TABLE ROW (행) 선별 함수 ******
void CLA::select_table_row() {                                          // table_row 배열 요소 추출
    int trap = 0, temp = 0, num = 0, check = -1, i = 0, j = 0;
    while (trap != -1) {
        check = -1;
        temp = 0;
        if (i < 30) {                                                   // second 배열의 최대값을 넘기지 않을 때
            if (second_prime_key_num[i][j] != -1) {
                num = second_prime_key_num[i][j];                       // num에 숫자들을 집어넣고
                check = 0;                                              // check를 0으로, temp = 1 (선별하기 위함)
                temp = 1;
            }
            for (int x = 0; x < 16; x++) {
                if (num == table_array_row[x])                      // num에 해당 숫자가 이미 있으면
                    check += 1;                                     // check 증가
            }
            if (check == 0 && temp == 1) {                          // 해당 숫자가 없고 temp가 1이면 (최소항에 존재하는 수이면)
                table_array_row[trap] = num;                        // table_row에 삽입
                trap += 1;
            }
            if (j < 3) j += 1;                                      // j가 2 이하면 계속 반복하고 
            else {                                                  // 3이면 i를 증가시키고 j를 초기화
                i += 1;
                j = 0;
            }
        }
        else {
            trap = -1;
            break;
        }
    }
    sort(table_array_row, table_array_row + 16);                    // table_row 정렬
}
// ****** EPI 선별 함수 ******
void CLA::select_pi_key(int x) {                                    // 첫 번째 epi 키 삽입 함수
    int count = 0, trap = 0;
    while (trap != -1) {
        count = -1;
        if (trap < 16) {                                            // table_col의 인덱스를 넘기지 않을 때까지
            count = 0;
            for (int i = 0; i < 30; i++) {
                if (table_array_col[i][0] != -1) {                  // table_col의 값이 존재하고
                    for (int j = 0; j < 4; j++) {
                        if (table_array_col[i][j] != -1 && x != i) {    // 각 숫자가 -1이 아니고, 해당 최소항 말고 다른 최소항에서
                            if (trap == table_array_col[i][j]) count += 1;  // 숫자가 table_col의 다른 최소항에 존재한다면 count 증가시켜 체크 
                        }
                    }
                }
            }
            if (count == 0 && array_x[trap] == 1)       // 숫자가 하나도 같지 않고, 최소항에 등록된 숫자라면  
                array_x[trap] = 2;                      // epi로 바꿔줌
            trap += 1;
        }
        else {
            trap = -1;
            break;
        }
    }
}
void CLA::select_pi_key_2(int x) {                                      // 추가 epi 키 삽입 함수
    int check_arr[4] = { -1, -1, -1, -1 };
    int check = 0;
    for (int i = 0; i < 4; i++) {
        check_arr[i] = table_array_col[x][i];                           // 현재 인덱스의 최소항 숫자를 check_arr에 넣어줌
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (essential_pi_num[i][j] == check_arr[j] && essential_pi_num[i][0] != -1)     // 만약 현재 인덱스의 최소항이 epi_num에 등록된 것과 같다면
                check += 1;                                             // check 증가
        }
        if (check != 4) check = 0;                                      // 완전히 같지 않다면 check 초기화
        else break;                                                     // 같으면 바로 중지
    }
    for (int i = 0; i < 16; i++) {
        if (essential_pi_num[i][0] != -1) {                             // epi_num에 값이 존재하고
            for (int j = 0; j < 4; j++) {
                if (essential_pi_num[i][j] != -1) {                     // 해당 값이 -1이 아닐 때
                    repeat_num[repeat_key] = essential_pi_num[i][j];    // 반복을 선별할 repeat_num에 삽입시키고
                    repeat_key += 1;                                    // 인덱스 증가
                }
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        if (check == 4) {                                       // epi에 이미 등록됐다면 (최소항이라면)
            if (array_x[i] == 1) {                              // 'x' 였던 인덱스 전부
                array_x[i] = 3;                                 // '-' 로 변경 (최소항 인덱스라서 지워짐)
            }
        }
        else {
            if (repeat_num[i] != -1) {                          // 최소항은 아니고 만약 값이 존재하는 경우라면
                array_x[repeat_num[i]] = 3;                     // 중복되는 값만 지워짐
            }
        }
    }
}
// ****** 논리식 변경 함수 ******
void CLA::change_alpha(int x) {                                 // 최소항 구조의 기호를 논리식으로 변경하는 함수
    int trap = 0;
    while (trap != -1) {                                        // 4자리까지 반복
        switch (trap) {                                         // trap : 각 자리수
        case 0:
            if (essential_pi_char[x][trap] == '0') {            // 첫 번째 자리수에서 0이면 A', 1이면 A 출력
                cout << "A'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "A";
            }
            break;
        case 1:
            if (essential_pi_char[x][trap] == '0') {            // 두 번째 자리수에서 0이면 B', 1이면 B 출력
                cout << "B'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "B";
            }
            break;
        case 2:
            if (essential_pi_char[x][trap] == '0') {            // 세 번째 자리수에서 0이면 C', 1이면 C 출력
                cout << "C'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "C";
            }
            break;
        case 3:
            if (essential_pi_char[x][trap] == '0') {            // 네 번째 자리수에서 0이면 D', 1이면 D 출력
                cout << "D'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "D";
            }
            break;
        }
        trap += 1;
        if (trap == 4) {
            trap = -1;
            break;
        }
    }


}
// ************* 출력 함수 *************
void CLA::print_all_table() {                                   // 2진수 십진 테이블 표 출력 함수
    cout << endl << "  A | B | C | D | X " << endl;
    cout << " -------------------" << endl;
    for (int i = 0; i < 16; i++) {
        cout << "  ";
        for (int j = 0; j < 5; j++) {
            cout << table_2_arr[i][j];
            if (j < 4) cout << " | ";
        }
        cout << "   (" << i << ")" << endl << " -------------------" << endl;
    }
}

void CLA::print_group_table(int counts) {                       // 첫 번째 1의 개수 그룹핑 표 출력 함수 (table_arr에서 추출)
    for (int i = 0; i < 16; i++) {
        if (arr[i] == counts) {
            cout << "  " << counts << " | ";
            for (int j = 0; j < 4; j++) {
                cout << table_2_arr[i][j];
                if (j < 3) cout << " | ";
            }
            cout << "  (" << i << ")" << endl;
        }
    }
}

void CLA::print_group_table2(int counts) {                      // 두 번째 1의 개수 그룹핑 표 출력 함수 (first_num에서 추출)
    for (int i = 0; i < 30; i++) {
        if (arr2[i] == counts && first_prime_key_char[i][0] != 'a') {
            cout << "  " << counts << " | ";
            for (int j = 0; j < 4; j++) {
                cout << first_prime_key_char[i][j];
                if (j < 3) cout << " | ";
            }
            cout << "  (" << first_prime_key_num[i][0] << ", " << first_prime_key_num[i][1] << ")" << endl;
        }
    }
}

void CLA::print_final_key() {                                   // 선별된 최소항 출력 함수 (second_num에서 추출)
    for (int i = 0; i < 30; i++) {
        if (second_prime_key_num[i][0] != -1) {
            cout << " ( ";
            for (int j = 0; j < 4; j++) {
                if (second_prime_key_num[i][j] != -1) cout << second_prime_key_num[i][j] << " ";
            }
            cout << ") : ";
            for (int j = 0; j < 4; j++) {
                cout << second_prime_key_char[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void CLA::print_prime_table(int temp) {                         // 테이블 표 출력 함수 (temp 0:기본, 1:epi추출, 2:추가epi추출)
    cout << "              |  ";
    for (int i = 0; i < 16; i++) {
        if (table_array_row[i] != -1) {
            cout << table_array_row[i] << "  ";                 // 행 기준 (포함된 숫자 전체) 출력
        }
    }
    cout << endl << " ----------------------------------------------------- " << endl;
    for (int i = 0; i < 30; i++) {
        if (table_array_col[i][0] != -1) {                      // table_col에 값이 존재할 경우
            cout << " (";
            for (int j = 0; j < 4; j++) {
                if (table_array_col[i][2] != -1) {              // 3번째 숫자가 -1인 경우 (first의 최소항)
                    cout << table_array_col[i][j];
                    if (j != 3) cout << ",";
                    else {
                        cout << ")";
                        print_table_space(i);                   // 자리수에 맞는 공백 출력
                        if (temp == 0) print_table_x(i);        // 각 단계별로 print_table 실행, 첫 번째 테이블 표 출력 함수
                        else if (temp == 1) print_table_x2(i);  // 두 번째 테이블 표 출력 함수 (첫 번째 epi 선택)
                        else if (temp == 2) print_table_x3(i);  // 최종 테이블 표 출력 함수 (추가 epi 선택)
                        cout << endl;
                    }
                }
                else {                                          // 3번째 숫자가 있는 경우 (second의 최소항)
                    if (j == 0) cout << table_array_col[i][j] << ",";
                    else if (j == 1) {
                        cout << table_array_col[i][j] << ")    ";
                        print_table_space(i);                   // 자리수에 맞는 공백 출력
                        if (temp == 0) print_table_x(i);        // 첫 번째 테이블 표 출력 함수
                        else if (temp == 1) print_table_x2(i);  // 두 번째 테이블 표 출력 함수 (첫 번째 epi 선택)
                        else if (temp == 2) print_table_x3(i);  // 최종 테이블 표 출력 함수 (추가 epi 선택)
                        cout << endl;
                    }
                }
            }
        }
    }
}

void CLA::print_table_basic(int x) {                            // 테이블 표 기본 0과 1 출력 함수
    for (int i = 0; i < 16; i++) {
        if (table_array_row[i] != -1) {                         // table_row에 존재하는 숫자인 경우
            array_x[table_array_row[i]] = 0;                    // array_x에 0 삽입
        }
    }

    for (int i = 0; i < 4; i++) {
        if (table_array_col[x][i] != -1) {                      // 해당 table_col이 존재할 경우
            for (int j = 0; j < 16; j++) {
                if (table_array_row[j] == table_array_col[x][i]) {  // table_col과 row가 같으면 (최소항에 포함되있는 경우)
                    array_x[table_array_col[x][i]] = 1;             // array_x에 1 삽입 ('x' 출력)
                }
            }
        }
    }
}
void CLA::print_table_x(int x) {                                // 첫 번째 테이블 표 출력 함수
    print_table_basic(x);                                       // 테이블 표에 0과 1 삽입
    cout << " ";
    for (int i = 0; i < 16; i++) {
        if (array_x[i] != -1) {                                 // 값이 존재할 경우
            if (i > 9) {
                if (array_x[i] == 0) cout << "    ";            // 0이면 공백 출력
                if (array_x[i] == 1) cout << "  x ";            // 1이면 x 출력
            }
            else {
                if (array_x[i] == 0) cout << "   ";
                if (array_x[i] == 1) cout << " x ";
            }
        }
    }
}

void CLA::print_table_x2(int x) {                               // 두 번째 테이블 표 출력 함수 (첫 번째 epi 선택)
    print_table_basic(x);                                       // 테이블 표에 0과 1 삽입
    select_pi_key(x);                                           // 첫 번째 epi 키 선별
    cout << " ";
    for (int i = 0; i < 16; i++) {
        if (array_x[i] != -1) {                                 // 값이 존재할 경우
            if (i > 9) {
                if (array_x[i] == 0) cout << "    ";            // 0이면 공백 출력
                if (array_x[i] == 1) cout << "  x ";            // 1이면 x 출력
                if (array_x[i] == 2) {                          // 2이면 ⓧ 출력
                    cout << " ⓧ ";
                    removeDouble(x);                            // essential 배열 반복 제거
                }
            }
            else {
                if (array_x[i] == 0) cout << "   ";
                if (array_x[i] == 1) cout << " x ";
                if (array_x[i] == 2) {
                    cout << " ⓧ";   // ○  
                    removeDouble(x);
                }
            }
        }
    }
}

void CLA::print_table_x3(int x) {                                // 최종 테이블 표 출력 함수 (추가 epi 선택)
    int add_array[4] = { -1, -1, -1, -1 };
    int index = 0, count = 0;
    print_table_basic(x);                                       // 테이블 표에 0과 1 삽입
    select_pi_key(x);                                           // 첫 번째 epi 키 선별
    select_pi_key_2(x);                                         // 추가 epi 키 선별

    for (int i = 0; i < 16; i++) {
        if (array_x[i] == 1) {                                  // -로 바뀐 뒤 현재 최소항에 살아있는 수 전부 받아와서
            add_array[index] = i;                               // 최소항을 add_array에 저장
            index += 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (table_array_col[x][2] != -1) {                      // 3번째 값이 존재할 경우 (second_num의 최소항)
            if (add_array[i] == table_array_col[x][i] && add_array[i] != -1) {  // 최소항과 현재 최소항이 같으면
                count += 1;                                                     // count 증가
            }
        }
        else {
            if (add_array[i] == table_array_col[x][i] && add_array[i] != -1) {  // 3번째 값이 존재하지 않을 경우 (first_num의 최소항)
                count += 2;                                                     // count 2씩 증가
            }
        }
    }
    if (count == 4) {                                   // 전부 살아남았다고 판별된다면
        for (int i = 0; i < 4; i++) {
            array_x[add_array[i]] = 2;                  // array_x를 2(ⓧ)로 바꿔주기
        }
    }
    cout << " ";
    for (int i = 0; i < 16; i++) {
        if (array_x[i] != -1) {                                 // 값이 존재할 경우
            if (i > 9) {
                if (array_x[i] == 0) cout << "    ";            // 0이면 공백 출력
                if (array_x[i] == 1) cout << "  x ";            // 1이면 x 출력
                if (array_x[i] == 2) {                          // 2이면 ⓧ 출력
                    cout << " ⓧ ";
                    removeDouble(x);                            // essential 배열 반복 제거
                }
                if (array_x[i] == 3) cout << "  - ";            // 3이면 - 출력
            }
            else {
                if (array_x[i] == 0) cout << "   ";
                if (array_x[i] == 1) cout << " x ";
                if (array_x[i] == 2) {
                    cout << " ⓧ";
                    removeDouble(x);
                }
                if (array_x[i] == 3) cout << " - ";
            }
        }
    }
}
void CLA::print_table_space(int x) {                // 테이블 표에서 자리수에 따른 공백 출력 함수
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (table_array_col[x][i] != -1) {
            if (table_array_col[x][i] > 9) count += 1;
        }
    }
    if (count == 0) cout << "    |";
    if (count == 1) cout << "   |";
    if (count == 2) cout << "  |";
    if (count == 3) cout << " |";
    if (count == 4) cout << "|";
}

int CLA::next_skip() {                  // 다음 화면으로 넘어가는 함수
    int input = 0, move_check = 0;

    while (input != 32) {
        if (_kbhit() == true) {        // 키보드 입력 확인 (true / false)
            input = _getch();
            if (input == 0x00 || input == 0xE0)
                input = _getch();
            if (input == 32) {          // 키보드가 입력된 경우
                move_check = 1;         // 변수 값 1로 변경
                break;
            }
        }
    }
    return move_check;                  // 변수값 반환
}