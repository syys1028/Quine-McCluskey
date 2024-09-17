#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <algorithm>

class CLA {                                     // CLASS CLA ����
public:
    // ************* �������� ************* //

    // 2������ �̷���� �������̺�
    char table_2_arr[16][5] = { {'0','0','0','0','0'}, {'0','0','0','1','0'}, {'0','0','1','0','0'}, {'0','0','1','1','0'}, // 0 1 2 3
             {'0','1','0','0','0'}, {'0','1','0','1','0'}, {'0','1','1','0','0'}, {'0','1','1','1','0'},             // 4 5 6 7
             {'1','0','0','0','0'}, {'1','0','0','1','0'}, {'1','0','1','0','0'}, {'1','0','1','1','0'},             // 8 9 10 11
             {'1','1','0','0','0'}, {'1','1','0','1','0'}, {'1','1','1','0','0'}, {'1','1','1','1','0'} };           // 12 13 14 15 

    // ���õ� �ּ��� �迭 (num �迭�� 10���� ����, char �迭�� ������ ���������, num �迭�� -1, char �迭�� a�� �ʱ�ȭ
    int first_prime_key_num[30][2];             // ù ��° �ּ��� �񱳿��� ���Ǵ� �迭 (10���� ����, �ʱ���� -1)
    char first_prime_key_char[30][4];           // ù ��° �ּ��� �񱳿��� ���Ǵ� �迭 (����, �ʱ���� 'a')

    int second_prime_key_num[30][4];            // �� ��° �ּ��� �񱳿��� ���Ǵ� �迭 (10���� ����, �ʱ���� -1)
    char second_prime_key_char[30][4];          // �� ��° �ּ��� �񱳿��� ���Ǵ� �迭 (����, �ʱ���� 'a')
    int key_index, key_index2;                  // first_num �迭�� second_num �迭�� index �� (�ش�Ǵ� ���� �迭�� �߰��ϱ� ���� �ʿ�)

    int essential_pi_num[16][4];                // ���� PI Ű �迭 (10���� ����, �ʱ���� -1)
    char essential_pi_char[16][4];              // ���� PI Ű �迭 (����, �ʱ���� 'a')
    int pi_index = 0;                           // essential_num �迭�� index ��

    int repeat_num[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // second_num �迭���� �ߺ��� ���� �����ϱ� ���� �迭
    int repeat_key = 0;                         // repeat_num �迭�� index ��

    // �ε��� �迭
    int arr[16] = { -1, };                      // table_arr 1�� ���� �迭 (�迭�� ��:2�������� 1�� ����, 0:�ʱ����, -1:���õ�������, 1�̻�:���õ�)
    int arr2[30] = { -1, };                     // first_num 1�� ���� �迭 (�迭�� ��:2�������� 1�� ����, 0:�ʱ����, -1:���õ�������, 1�̻�:���õ�) 
    int array_x[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // ���̺� ǥ���� �� �ּ����� �� ��¹迭 (0:�ش� �ּ��׿� ����, -1:��ü �ּ��׿� ����, 1:�ش簪, 2:���� piŰ, 3:����� Ű) 

    int table_array_row[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; // ���̺� ǥ���� �����ϴ� ��ü ���� �迭 (��)
    int table_array_col[30][4];                 // ���̺� ǥ���� �����ϴ� ��ü �ּ��� �迭 (��)

    // ************* �Լ� ȣ�� *************
    void manage();                              // �⺻ ȣ�� �Լ�
    void f1_input_num();                        // �Լ�1 : ���� �����ϱ�
    void f2_grouping1();                        // �Լ�2 : 1�ܰ� - 1�� ������ �׷���
    void f3_checkBit_1();                       // �Լ�3 : 1�ܰ� - 1�� ���� üũ
    void f4_grouping2();                        // �Լ�4 : 2�ܰ� - 1�� ������ �׷���
    void f5_checkBit_2();                       // �Լ�5 : 2�ܰ� - 1�� ���� üũ
    void f6_select_prime_key();                 // �Լ�6 : prime Ű �����ϱ�
    void f7_prime_table();                      // �Լ�7 : ���̺� ǥ �ۼ�
    void f8_essential_key();                    // �Լ�8 : �߰� epi ���� �� ���̺� ǥ ���ۼ�
    void f9_final_expression();                 // �Լ�9 : ���� epi ���� �� ���� ���

    void resetArray();                          // �迭 �ʱ�ȭ �Լ� (first �迭)
    void resetArray2();                         // �迭 �ʱ�ȭ �Լ� (second �迭)
    void resetArray3();                         // �迭 �ʱ�ȭ �Լ� (essential �迭)

    void compareBit(int index1, int index2);    // ù ��° �������� �� �� ��� �Լ�
    void compareBit2(int index1, int index2);   // �� ��° �������� �� �� ��� �Լ�
    void sortArray(int arr[][4], int rows);     // 2���� �迭 ���� �Լ�
    void select_table_row();                    // table_row �迭 ��� ����
    void select_pi_key(int x);                  // ù ��° epi Ű ���� �Լ�
    void select_pi_key_2(int x);                // �߰� epi Ű ���� �Լ�
    void change_alpha(int x);                   // �ּ��� ������ ��ȣ�� �������� �����ϴ� �Լ�

    void removeRepeat();                        // second �迭 �ݺ� ���� �Լ�
    void removeDouble(int x);                   // essential �迭 �ݺ� ���� �Լ�

    void print_all_table();                     // 2���� ���� ���̺� ǥ ��� �Լ�
    void print_group_table(int counts);         // ù ��° 1�� ���� �׷��� ǥ ��� �Լ� (table_arr���� ����)
    void print_group_table2(int counts);        // �� ��° 1�� ���� �׷��� ǥ ��� �Լ� (first_num���� ����)
    void print_final_key();                     // ������ �ּ��� ��� �Լ� (second_num���� ����)
    void print_prime_table(int temp);           // ���̺� ǥ ��� �Լ� (temp 0:�⺻, 1:epi����, 2:�߰�epi����)
    void print_table_basic(int x);              // ���̺� ǥ �⺻ 0�� 1 ��� �Լ�
    void print_table_x(int x);                  // ù ��° ���̺� ǥ ��� �Լ�
    void print_table_x2(int x);                 // �� ��° ���̺� ǥ ��� �Լ� (ù ��° epi ����)
    void print_table_x3(int x);                 // ���� ���̺� ǥ ��� �Լ� (�߰� epi ����)
    void print_table_space(int x);              // ���̺� ǥ���� �ڸ����� ���� ���� ��� �Լ�

    int next_skip();                            // ���� ȭ������ �Ѿ�� �Լ�
};

using namespace std;

int main() {                                    // ���� �Լ�
    CLA nm;                                     // Ŭ���� ����
    nm.manage();                                // �⺻ �Լ� ȣ��
    return 0;
}

void CLA::manage() {                            // �⺻ ȣ�� �Լ�
    f1_input_num();                             // �Լ�1 ȣ��
}

// ************* �ܰ躰 �Լ� *************
void CLA::f1_input_num() {                             // �Լ�1 : ���� �����ϱ�
    int input = 0;
    cout << endl << "  < �ּ������� ����� ���� ���� > (1:���, 0 :������)" << endl;
    cout << endl << "      A | B | C | D | X " << endl;
    cout << " -----------------------" << endl;
    for (int i = 0; i < 16; i++) {
        if (i >= 10) cout << " (" << i << ")";          // �ڸ����� ���� 10���� ���
        else cout << " (" << i << ") ";
        cout << " ";
        for (int j = 0; j < 5; j++) {                   // 2���� ���
            if (j != 4) {                               // �ڸ����� ���� �������� �����ϰ� | ���
                cout << table_2_arr[i][j];
                if (j < 4) cout << " | ";
            }
            else {
                cin >> input;                               // j�� 4�̸� ���� �Է¹ޱ�
                if (input == 1) table_2_arr[i][4] = '1';    // 1�̸� ����
                else table_2_arr[i][4] = '0';               // �׿ܴ� ���� 0
            }
        }
    }
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {                                 // �����̽� �ٸ� Ŭ���ϸ� ���� �Լ��� �Ѿ
        system("cls");
        cout << endl << endl << "  < �ϼ��� ������ ���̺� >" << endl;
        print_all_table();                                  // ���õ� 2���� ���� ���̺� ǥ ���
    }
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        f2_grouping1();                                     // �Լ�2 ȣ��
    }
}

void CLA::f2_grouping1() {                                  // �Լ�2 : 1�ܰ� - 1�� ������ �׷���
    int count = 0;
    for (int i = 0; i < 16; i++) {
        count = 0;
        if (table_2_arr[i][4] == '1') {                     // table_arr���� ������ ���ڸ� ���
            for (int j = 0; j < 4; j++) {
                if (table_2_arr[i][j] == '1')               // 1�� ������ count�� ����
                    count += 1;
            }
            arr[i] = count;                                 // arr�迭�� �ε����� 1�� ���� ���� 
        }
        else arr[i] = -1;                                   // ���õ��� �ʾҴٸ� -1 ����
    }
    cout << endl << "  < 1�ܰ� >" << endl << "  < 1�� ������ �׷��� >" << endl;
    cout << endl << "    | A | B | C | D " << endl;
    cout << " -------------------" << endl;
    for (int i = 0; i < 5; i++) {                           // 1�� ���� 0���� 4����
        print_group_table(i);                               // �׷��� ǥ ���
        cout << " -------------------" << endl;
    }
    f3_checkBit_1();                                    // �Լ�3 �̾ ȣ��
}

void CLA::f3_checkBit_1() {                             // �Լ�3 : 1�ܰ� - 1�� ���� üũ
    int trap = 0, i = 0, j = 0;                         // trap : 1�� ����
    int index_1 = -1, index_2 = -1;
    key_index = 0;                                      // first_num�� �ε��� �� �ʱ�ȭ
    cout << endl << endl << "  < �������� �� #1 >" << endl;
    resetArray();                                       // first �迭 �ʱ�ȭ
    cout << endl << "  A | B | C | D " << endl;
    cout << " ---------------" << endl;
    if (arr[0] != 0) trap += 1;                         // 0�� ���õ��� �ʾҴٸ� (0�� 1�ǰ��� 0�� �Էµ��� �ʾҴٸ�) trap = 1���� ����
    while (trap < 5) {                                  // trap�� 4�� ������ �ݺ�
        for (i = 0; i < 16; i++) {
            if (arr[i] == trap && arr[i] != -1)         // ���õǰ� 1�� ������ trap�� ���ٸ�
                if (index_1 < i) {                      // index1�� ����� ���ں��� ���� i�� Ŭ �� (������ ���� �� �϶�),
                    index_1 = i;                        // ���� i(�ε���)�� index1�� ���� �� ����
                    break;
                }
        }
        if (index_1 == -1) trap += 1;
        if (index_1 != -1 && i != 16) {                                      // i�� �߰��� ����ٸ�
            for (j = 0; j < 16; j++) {
                if (arr[j] == trap + 1 && arr[j] != -1) {   // ��������(trap + 1)���� ���õǰ� 1�� ������ trap+1�� ���ٸ�
                    index_2 = j;                            // index2�� ���� ��
                    compareBit(index_1, index_2);           // �� �Լ� ���� (���� ������ ������ �ݺ�)
                }
            }
        }
        else if (i == 16 && j == 16) {                      // �������� �񱳸� ���� �����ƴٸ�
            trap += 1;                                      // ���� trap���� �̵� ��, index �ʱ�ȭ
            index_1 = -1;
            index_2 = -1;
            if (trap == 4) break;                           // ���� trap+1�� 4�� �����ߴٸ� �ݺ� ����
        }
        if (index_1 != -1 && index_2 != -1) cout << " ---------------" << endl;
    }
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        f4_grouping2();                                     // �Լ�4 ȣ��
    }
}

void CLA::f4_grouping2() {                              // �Լ�4 : 2�ܰ� - 1�� ������ �׷���
    cout << endl << "  < 2�ܰ� >" << endl << "  < 1�� ������ �׷��� #2 >" << endl;
    int count = 0;
    for (int i = 0; i < 30; i++) {
        if (i <= key_index) {                           // first �迭�� �ε����� ���� ���� ���
            count = 0;
            for (int j = 0; j < 4; j++) {
                if (first_prime_key_char[i][j] == '1')  // first_char���� ������ ���ڸ� ���
                    count += 1;                         // 1�� ������ count�� ����
            }
            arr2[i] = count;                            // arr2�迭�� �ε����� 1�� ���� ���� 
        }
        else arr2[i] = -1;                              // ���õ��� �ʾҴٸ� -1 ����
    }
    cout << endl << "      A | B | C | D " << endl;
    cout << " -------------------" << endl;

    for (int i = 0; i < 4; i++) {                       // 1�� ���� 0���� 4����
        print_group_table2(i);                          // �׷��� ǥ ���
        cout << " -------------------" << endl;
    }
    f5_checkBit_2();                                     // �Լ�5 �̾ ȣ��
}

void CLA::f5_checkBit_2() {                                     // �Լ�5 : 2�ܰ� - 1�� ���� üũ
    int trap = 0, i = 0, j = 0, index_1 = -1, index_2 = -1;     // trap : 1�� ����
    key_index2 = 0;                                             // second_num�� �ε��� �� �ʱ�ȭ
    cout << endl << endl << "  < �������� �� #2 >" << endl;
    resetArray2();                                              // second_prime_key �ʱ�ȭ
    cout << endl << "  A | B | C | D " << endl << " ---------------" << endl;
    if (arr2[0] != 0) trap += 1;                                // 0�� ���õ��� �ʾҴٸ� (0�� 1�ǰ��� 0�� �Էµ��� �ʾҴٸ�) trap = 1���� ����
    while (trap < 5) {                                          // trap�� 4�� ������ �ݺ�
        for (i = 0; i < 30; i++) {
            if (arr2[i] == trap && arr2[i] != -1)               // ���õǰ� 1�� ������ trap�� ���ٸ�
                if (index_1 < i) {                              // index1�� ����� ���ں��� ���� i�� Ŭ �� (������ ���� �� �϶�),
                    index_1 = i;                                // ���� i(�ε���)�� index1�� ���� �� ����
                    break;
                }
        }
        if (index_1 == -1) trap += 1;
        if (index_1 != -1 && i != 30) {                                           // i�� �߰��� ����ٸ�
            for (j = 0; j < 30; j++) {
                if (arr2[j] == trap + 1 && arr2[j] != -1) {     // ��������(trap + 1)���� ���õǰ� 1�� ������ trap+1�� ���ٸ�
                    index_2 = j;                                // index2�� ���� ��
                    compareBit2(index_1, index_2);              // �� �Լ� ���� (���� ������ ������ �ݺ�)
                }
                else {
                    if (index_2 == -1) {
                        if (arr2[j] == trap + 2 && arr2[j] != -1) {     // ��������(trap + 2)���� ���õǰ� 1�� ������ trap+2�� ���ٸ�
                            index_2 = j;                                // index2�� ���� ��
                            compareBit2(index_1, index_2);              // �� �Լ� ���� (���� ������ ������ �ݺ�)
                        }
                        else {
                            if (arr2[j] == trap + 3 && arr2[j] != -1) {     // ��������(trap + 3)���� ���õǰ� 1�� ������ trap+3�� ���ٸ�
                                index_2 = j;                                // index2�� ���� ��
                                compareBit2(index_1, index_2);              // �� �Լ� ���� (���� ������ ������ �ݺ�)
                            }
                        }
                    }
                }
            }
        }
        else if (i == 30 && j == 30) {                          // �������� �񱳸� ���� �����ƴٸ�
            trap += 1;                                          // ���� trap���� �̵� ��, index �ʱ�ȭ
            index_1 = -1;
            index_2 = -1;
            if (trap == 4) break;                               // ���� trap+1�� 4�� �����ߴٸ� �ݺ� ����
        }
        if (index_1 != -1 && index_2 != -1) cout << " ---------------" << endl;
    }
    cout << endl;
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        f6_select_prime_key();                                  // �Լ�6 ȣ��
    }
}

void CLA::f6_select_prime_key() {                               // �Լ�6 : prime Ű �����ϱ�
    int check_arr[2] = { -1, -1 };                              // �߰��� first num Ű �迭
    int index_arr[30] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // second num Ű �ε��� �迭 *****************
       -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int check = 0, trap = 0, index = 0;

    while (trap < 30) {                                         // trap(first num�� �ε���)�� 30 ������ ��  
        if (first_prime_key_num[trap][0] != -1) {               // �ش� �ε����� ���� ���������
            for (int j = 0; j < 2; j++) {
                check_arr[j] = first_prime_key_num[trap][j];    // check_arr�� �־
            }
            for (int i = 0; i < 30; i++) {
                check = 0;
                for (int j = 0; j < 4; j++) {
                    if (check_arr[0] == second_prime_key_num[i][j]) check += 1;         // second_num �迭�� ���Ͽ� ������ check�� ����
                    else if (check_arr[1] == second_prime_key_num[i][j]) check += 1;
                }
                if (check > 1) {                                // check�� 2�̻��� �� (���ڽ��� second_num�� �̹� ���ԵǾ� ���� ��)
                    first_prime_key_num[trap][0] = -1;          // �� �ּ����� ������ -1�� �����Ͽ� �������� (�ߺ� ����)
                }
            }
        }
        trap += 1;
    }
    for (int i = 0; i < 30; i++) {
        if (first_prime_key_num[i][0] != -1) {                  // ���� first_num���� �������� ���� �ּ����� (second_num�� ���ԵǾ� ���� ���� ���)
            index_arr[index] = i;                               // index_arr�� first_num �ε��� ���� �ְ� index_arr�� index�� ����
            index += 1;
        }
    }
    removeRepeat();                                             // second �迭 �ݺ� ���� �Լ� ����
    index = 0;
    trap = 0;
    while (trap != -1) {
        if (index_arr[index] != -1) {                           // index_arr�� ���� ������ �� (�ʱⰪ�� �ƴ� ��)
            for (int i = 0; i < 30; i++) {
                if (second_prime_key_num[i][0] == -1) {         // ���� second_num�� ���������
                    second_prime_key_num[i][0] = first_prime_key_num[index_arr[index]][0];  // first_num���� �������� ���� �ּ����� �ε����� �ְ� second_num�� ����
                    second_prime_key_num[i][1] = first_prime_key_num[index_arr[index]][1];  // first_num�� 2��¥�� �ּ����̴ϱ� 0�� 1�� ����
                    for (int j = 2; j < 4; j++) {
                        second_prime_key_num[i][j] = -1;        // 2�� 3���� -1 ����
                    }
                    for (int j = 0; j < 4; j++) {
                        second_prime_key_char[i][j] = first_prime_key_char[index_arr[index]][j];    // second_char���� �Ȱ��� �ش� �ε����� ���� ����
                    }
                    break;
                }
            }
            index += 1;     // index �����Ͽ� �ݺ�
        }
        else {
            trap = -1;
            break;
        }
    }
    cout << endl << endl << "  < ���� ������ �ּ��� >" << endl << endl;
    print_final_key();                                                      // second_num�� ����� �ּ��� ��� �Լ�
    cout << endl;
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        f7_prime_table();                                                   // �Լ�7 ȣ��
    }
}

void CLA::f7_prime_table() {                                                // �Լ�7 : ���̺� ǥ �ۼ�
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 4; j++) {
            if (second_prime_key_num[i][j] != -1) {                         // second_num�� ���� ����� ���
                table_array_col[i][j] = second_prime_key_num[i][j];         // table_col(�ּ��� ��)�� �Űܴ���
            }
            else table_array_col[i][j] = -1;                                // ������ -1 ����
        }
    }
    select_table_row();                                                     // table_row �迭 ��� ���� �Լ�
    cout << endl << endl << "  < �ּ��� ���̺� >" << endl << endl;
    print_prime_table(0);                                                   // ���̺� ǥ ��� �Լ� (0:�ʱ� ����)
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        f8_essential_key();                                                 // �Լ� 8 ȣ��
    }
}

void CLA::f8_essential_key() {                                              // �Լ�8 : �߰� epi ���� �� ���̺� ǥ ���ۼ�
    cout << endl << endl << "  < Essential PI ���� >" << endl << endl;
    resetArray3();                                                          // �迭 �ʱ�ȭ �Լ� (essential �迭)
    print_prime_table(1);                                                   // ���̺� ǥ ��� �Լ� (1:epi����)
    sort(repeat_num, repeat_num + 16);                                      // second_num�� �ߺ��� ���ڸ� ���� �迭 ���� 
    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        cout << endl << endl << "  < �߰� Essential PI Ȯ�� >" << endl << endl;
        print_prime_table(2);                                               // ���̺� ǥ ��� �Լ� (2:�߰�epi����)                                               
    }

    cout << endl << "  ...�������� �ѱ���� �����̽� �ٸ� Ŭ���ϼ���." << endl;
    if (next_skip() == 1) {
        system("cls");
        f9_final_expression();                                              // �Լ� 9 ȣ��
    }
}

void CLA::f9_final_expression() {                                           // �Լ�9 : ���� epi ���� �� ���� ���
    int trap = 0;
    cout << endl << endl << "  < ���� Essential PI Ű�� ��Ʈ > " << endl << endl;
    for (int i = 0; i < 16; i++) {
        if (essential_pi_num[i][0] != -1) {                                 // epi_num�� ���� �����ϴ� ���
            cout << "  ";
            for (int j = 0; j < 4; j++) {
                if (essential_pi_num[i][j] != -1) cout << essential_pi_num[i][j] << " ";    // -1�� �ƴ� ���� ���� ���
            }
            cout << ": ";
            for (int j = 0; j < 4; j++) {
                if (essential_pi_char[i][j] != 'a') cout << essential_pi_char[i][j] << " "; // 'a'�� �ƴ� ��ȣ ���� ���
            }
            cout << endl;
        }
    }
    cout << endl << endl << "  < ���� ���� ���� >" << endl << endl;
    cout << "  F = ";
    while (trap != -1) {
        if (essential_pi_num[trap][0] != -1) {                                 // epi_num�� ���� �����ϴ� ���
            change_alpha(trap);                                                // �������� ���� �Լ�
            if (trap < 14 && essential_pi_num[trap + 1][0] != -1) cout << " + ";  // + �Է�
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
// ************* ��� �Լ� *************
// ****** ���� ���� �� �Լ� ******
void CLA::compareBit(int index1, int index2) {                              // ù ��° �������� �� �� ��� �Լ�
    int count = 0, check = -1;
    char check_arr[4] = { '-', '-', '-', '-' };
    if (key_index < 30) {                                                   // Ű �ε����� 30�� ���� ���� ���
        for (int i = 0; i < 4; i++) {
            if (table_2_arr[index1][i] == table_2_arr[index2][i]) {         // table_arr���� ������ �ε����� ������ ��
                count += 1;                                                 // ������ count ����
                check_arr[i] = table_2_arr[index1][i];                      // ���� ���� �״�� ��� (�ٸ� �� '-' ���� �״��)
            }
        }
        cout << "  ";
        for (int i = 0; i < 4; i++) {                                       // ���� ���
            cout << check_arr[i];
            if (i < 3) cout << " | ";
        }
        if (count == 3) {                                                   // 3���� ���� ���
            first_prime_key_num[key_index][0] = index1;                     // 2���� �迭 first_num�� �ش� �ε��� ���� 
            first_prime_key_num[key_index][1] = index2;
            for (int i = 0; i < 4; i++) {
                first_prime_key_char[key_index][i] = check_arr[i];          // first_char�� ���� ����
            }
            check = 1;
            key_index += 1;                                                 // key index ����
        }
        cout << "  (" << index1 << ", " << index2 << ")";
        if (check == 1) {
            cout << "   �� ";

        }
        cout << endl;
    }
}

void CLA::compareBit2(int index1, int index2) {                             // �� ��° �������� �� �� ��� �Լ�
    int count = 0, check = -1;
    char check_arr[4] = { '-', '-', '-', '-' };
    if (key_index2 < 30 && first_prime_key_num[index1][0] != -1) {          // Ű �ε���2�� 30�� ���� ���� ���, first_num�� ���� ������� ���
        for (int i = 0; i < 4; i++) {
            if (first_prime_key_char[index1][i] == first_prime_key_char[index2][i]) { // first_char���� ������ �ε����� ������ ��
                count += 1;                                                 // ������ count ����
                check_arr[i] = first_prime_key_char[index1][i];             // ���� ���� �״�� ��� (�ٸ� �� '-' ���� �״��)
            }
        }
        cout << "  ";                                                       // ���� ���
        for (int i = 0; i < 4; i++) {
            cout << check_arr[i];
            if (i < 3) cout << " | ";
        }
        if (count == 3) {                                                   // 3���� ���� ��� ('-' ����)
            second_prime_key_num[key_index2][0] = first_prime_key_num[index1][0];   // 2���� �迭 second_num�� �ش� �ε��� ���� 
            second_prime_key_num[key_index2][1] = first_prime_key_num[index1][1];
            second_prime_key_num[key_index2][2] = first_prime_key_num[index2][0];
            second_prime_key_num[key_index2][3] = first_prime_key_num[index2][1];
            for (int i = 0; i < 4; i++) {
                second_prime_key_char[key_index2][i] = check_arr[i];                // second_char�� ���� ����
            }
            check = 1;
            key_index2 += 1;                                                        // key index ����
        }
        cout << "  (" << first_prime_key_num[index1][0] << ", " << first_prime_key_num[index1][1];
        cout << ", " << first_prime_key_num[index2][0] << ", " << first_prime_key_num[index2][1] << ")";
        if (check == 1) {
            if (index1 < 10 && index2 < 10) cout << "   �� ";
            else if ((index1 < 10 && index2 > 9) || (index1 > 9 && index2 < 10)) cout << "  �� ";
            else cout << " �� ";
        }
        cout << endl;
    }
}

// ****** �迭 �ʱ�ȭ �Լ� ******
void CLA::resetArray() {                                // �迭 �ʱ�ȭ �Լ� (first �迭)
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 2; j++) {
            first_prime_key_num[i][j] = -1;
        }
        for (int j = 0; j < 4; j++) {
            first_prime_key_char[i][j] = 'a';
        }
    }
}

void CLA::resetArray2() {                               // �迭 �ʱ�ȭ �Լ� (second �迭)
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 4; j++) {
            second_prime_key_num[i][j] = -1;
        }
        for (int j = 0; j < 4; j++) {
            second_prime_key_char[i][j] = 'a';
        }
    }
}

void CLA::resetArray3() {                               // �迭 �ʱ�ȭ �Լ� (essential �迭)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            essential_pi_num[i][j] = -1;
        }
        for (int j = 0; j < 4; j++) {
            essential_pi_char[i][j] = 'a';
        }
    }
}

// ****** ���� �Լ� ******
void CLA::sortArray(int arr[][4], int rows) {            // 2���� �迭 ���� �Լ�
    for (int i = 0; i < rows; ++i) {                     // �� ���ڱ��� �ݺ�
        for (int j = 0; j < 3; ++j) {
            int min = j;                                    // �ּ��� min�� j�� �Է��ϰ�
            for (int k = j + 1; k < 4; ++k) {               // k�� j�������� �ݺ�
                if (arr[i][k] < arr[i][min]) {              // ���� min�� k�� ������
                    min = k;                                // min�� k�� �Է�
                }
            }
            if (min != j) {                             // min�� ���� ����Ǹ�
                swap(arr[i][j], arr[i][min]);           // swap ����
            }
        }
    }
}

// ****** �ݺ� ���� �Լ� ******
void CLA::removeRepeat() {                                              // second �迭 �ݺ� ���� �Լ�
    int check_arr[4] = { -1, -1, -1, -1 };
    int check = 0, trap = 0;
    sortArray(second_prime_key_num, 30);                                // 2���� ���� �Լ��� ȣ���� second �迭�� ���ڵ��� �������� ����
    while (trap < 30) {                                                 // trap(second_num�� index)�� 30�� ���� ���� ��  *****************
        if (second_prime_key_num[trap][0] != -1) {                      // second �迭�� trap �ε��� ���� ����ִٸ�
            for (int j = 0; j < 4; j++) {
                check_arr[j] = second_prime_key_num[trap][j];           // �ּ����� ���ڵ��� check_arr�� ����
            }
            for (int i = 0; i < 30; i++) {
                check = 0;
                if (trap != i) {                                        // second_num���� �ش� �ּ����� �� �������� �ݺ��ϸ�
                    for (int j = 0; j < 4; j++) {
                        if (check_arr[j] == second_prime_key_num[i][j]) // check_arr�� ���� �ּ����� �ִ��� Ž��
                            check += 1;
                    }
                    if (check == 4) {                                   // ���� ������ 
                        second_prime_key_num[i][0] = -1;                // ���� ���� �����ϱ�
                    }
                }
            }
        }
        trap += 1;
    }
}
void CLA::removeDouble(int x) {                                         // essential �迭 �ݺ� ���� �Լ�
    int check_arr[4] = { -1, -1, -1, -1 };
    int check = 0;
    for (int i = 0; i < 4; i++) {
        check_arr[i] = table_array_col[x][i];                           // �Է¹��� �ε����� �ּ��� ���ڵ��� check_arr�� ����
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (essential_pi_num[i][j] == check_arr[j] && essential_pi_num[i][0] != -1) // epi_num���� check_arr�� ���� �ּ����� �ִ��� Ž��
                check += 1;
        }
        if (check != 4) check = 0;                                      // ���� ���� ������ check �ʱ�ȭ �� �ݺ�
        else break;                                                     // ������ ��� ����
    }
    if (check != 4) {                                                   // �ݺ����� �� ���� ������ ������
        for (int m = 0; m < 4; m++) {
            essential_pi_num[pi_index][m] = table_array_col[x][m];      // epi_num�� �ش� �ε����� ���� �Է�
            essential_pi_char[pi_index][m] = second_prime_key_char[x][m];   // epi_char���� �־���
        }
        pi_index += 1;                                                  // pi �ε��� ����
    }
}

// ****** TABLE ROW (��) ���� �Լ� ******
void CLA::select_table_row() {                                          // table_row �迭 ��� ����
    int trap = 0, temp = 0, num = 0, check = -1, i = 0, j = 0;
    while (trap != -1) {
        check = -1;
        temp = 0;
        if (i < 30) {                                                   // second �迭�� �ִ밪�� �ѱ��� ���� ��
            if (second_prime_key_num[i][j] != -1) {
                num = second_prime_key_num[i][j];                       // num�� ���ڵ��� ����ְ�
                check = 0;                                              // check�� 0����, temp = 1 (�����ϱ� ����)
                temp = 1;
            }
            for (int x = 0; x < 16; x++) {
                if (num == table_array_row[x])                      // num�� �ش� ���ڰ� �̹� ������
                    check += 1;                                     // check ����
            }
            if (check == 0 && temp == 1) {                          // �ش� ���ڰ� ���� temp�� 1�̸� (�ּ��׿� �����ϴ� ���̸�)
                table_array_row[trap] = num;                        // table_row�� ����
                trap += 1;
            }
            if (j < 3) j += 1;                                      // j�� 2 ���ϸ� ��� �ݺ��ϰ� 
            else {                                                  // 3�̸� i�� ������Ű�� j�� �ʱ�ȭ
                i += 1;
                j = 0;
            }
        }
        else {
            trap = -1;
            break;
        }
    }
    sort(table_array_row, table_array_row + 16);                    // table_row ����
}
// ****** EPI ���� �Լ� ******
void CLA::select_pi_key(int x) {                                    // ù ��° epi Ű ���� �Լ�
    int count = 0, trap = 0;
    while (trap != -1) {
        count = -1;
        if (trap < 16) {                                            // table_col�� �ε����� �ѱ��� ���� ������
            count = 0;
            for (int i = 0; i < 30; i++) {
                if (table_array_col[i][0] != -1) {                  // table_col�� ���� �����ϰ�
                    for (int j = 0; j < 4; j++) {
                        if (table_array_col[i][j] != -1 && x != i) {    // �� ���ڰ� -1�� �ƴϰ�, �ش� �ּ��� ���� �ٸ� �ּ��׿���
                            if (trap == table_array_col[i][j]) count += 1;  // ���ڰ� table_col�� �ٸ� �ּ��׿� �����Ѵٸ� count �������� üũ 
                        }
                    }
                }
            }
            if (count == 0 && array_x[trap] == 1)       // ���ڰ� �ϳ��� ���� �ʰ�, �ּ��׿� ��ϵ� ���ڶ��  
                array_x[trap] = 2;                      // epi�� �ٲ���
            trap += 1;
        }
        else {
            trap = -1;
            break;
        }
    }
}
void CLA::select_pi_key_2(int x) {                                      // �߰� epi Ű ���� �Լ�
    int check_arr[4] = { -1, -1, -1, -1 };
    int check = 0;
    for (int i = 0; i < 4; i++) {
        check_arr[i] = table_array_col[x][i];                           // ���� �ε����� �ּ��� ���ڸ� check_arr�� �־���
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            if (essential_pi_num[i][j] == check_arr[j] && essential_pi_num[i][0] != -1)     // ���� ���� �ε����� �ּ����� epi_num�� ��ϵ� �Ͱ� ���ٸ�
                check += 1;                                             // check ����
        }
        if (check != 4) check = 0;                                      // ������ ���� �ʴٸ� check �ʱ�ȭ
        else break;                                                     // ������ �ٷ� ����
    }
    for (int i = 0; i < 16; i++) {
        if (essential_pi_num[i][0] != -1) {                             // epi_num�� ���� �����ϰ�
            for (int j = 0; j < 4; j++) {
                if (essential_pi_num[i][j] != -1) {                     // �ش� ���� -1�� �ƴ� ��
                    repeat_num[repeat_key] = essential_pi_num[i][j];    // �ݺ��� ������ repeat_num�� ���Խ�Ű��
                    repeat_key += 1;                                    // �ε��� ����
                }
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        if (check == 4) {                                       // epi�� �̹� ��ϵƴٸ� (�ּ����̶��)
            if (array_x[i] == 1) {                              // 'x' ���� �ε��� ����
                array_x[i] = 3;                                 // '-' �� ���� (�ּ��� �ε����� ������)
            }
        }
        else {
            if (repeat_num[i] != -1) {                          // �ּ����� �ƴϰ� ���� ���� �����ϴ� �����
                array_x[repeat_num[i]] = 3;                     // �ߺ��Ǵ� ���� ������
            }
        }
    }
}
// ****** ���� ���� �Լ� ******
void CLA::change_alpha(int x) {                                 // �ּ��� ������ ��ȣ�� �������� �����ϴ� �Լ�
    int trap = 0;
    while (trap != -1) {                                        // 4�ڸ����� �ݺ�
        switch (trap) {                                         // trap : �� �ڸ���
        case 0:
            if (essential_pi_char[x][trap] == '0') {            // ù ��° �ڸ������� 0�̸� A', 1�̸� A ���
                cout << "A'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "A";
            }
            break;
        case 1:
            if (essential_pi_char[x][trap] == '0') {            // �� ��° �ڸ������� 0�̸� B', 1�̸� B ���
                cout << "B'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "B";
            }
            break;
        case 2:
            if (essential_pi_char[x][trap] == '0') {            // �� ��° �ڸ������� 0�̸� C', 1�̸� C ���
                cout << "C'";
            }
            else if (essential_pi_char[x][trap] == '1') {
                cout << "C";
            }
            break;
        case 3:
            if (essential_pi_char[x][trap] == '0') {            // �� ��° �ڸ������� 0�̸� D', 1�̸� D ���
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
// ************* ��� �Լ� *************
void CLA::print_all_table() {                                   // 2���� ���� ���̺� ǥ ��� �Լ�
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

void CLA::print_group_table(int counts) {                       // ù ��° 1�� ���� �׷��� ǥ ��� �Լ� (table_arr���� ����)
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

void CLA::print_group_table2(int counts) {                      // �� ��° 1�� ���� �׷��� ǥ ��� �Լ� (first_num���� ����)
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

void CLA::print_final_key() {                                   // ������ �ּ��� ��� �Լ� (second_num���� ����)
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

void CLA::print_prime_table(int temp) {                         // ���̺� ǥ ��� �Լ� (temp 0:�⺻, 1:epi����, 2:�߰�epi����)
    cout << "              |  ";
    for (int i = 0; i < 16; i++) {
        if (table_array_row[i] != -1) {
            cout << table_array_row[i] << "  ";                 // �� ���� (���Ե� ���� ��ü) ���
        }
    }
    cout << endl << " ----------------------------------------------------- " << endl;
    for (int i = 0; i < 30; i++) {
        if (table_array_col[i][0] != -1) {                      // table_col�� ���� ������ ���
            cout << " (";
            for (int j = 0; j < 4; j++) {
                if (table_array_col[i][2] != -1) {              // 3��° ���ڰ� -1�� ��� (first�� �ּ���)
                    cout << table_array_col[i][j];
                    if (j != 3) cout << ",";
                    else {
                        cout << ")";
                        print_table_space(i);                   // �ڸ����� �´� ���� ���
                        if (temp == 0) print_table_x(i);        // �� �ܰ躰�� print_table ����, ù ��° ���̺� ǥ ��� �Լ�
                        else if (temp == 1) print_table_x2(i);  // �� ��° ���̺� ǥ ��� �Լ� (ù ��° epi ����)
                        else if (temp == 2) print_table_x3(i);  // ���� ���̺� ǥ ��� �Լ� (�߰� epi ����)
                        cout << endl;
                    }
                }
                else {                                          // 3��° ���ڰ� �ִ� ��� (second�� �ּ���)
                    if (j == 0) cout << table_array_col[i][j] << ",";
                    else if (j == 1) {
                        cout << table_array_col[i][j] << ")    ";
                        print_table_space(i);                   // �ڸ����� �´� ���� ���
                        if (temp == 0) print_table_x(i);        // ù ��° ���̺� ǥ ��� �Լ�
                        else if (temp == 1) print_table_x2(i);  // �� ��° ���̺� ǥ ��� �Լ� (ù ��° epi ����)
                        else if (temp == 2) print_table_x3(i);  // ���� ���̺� ǥ ��� �Լ� (�߰� epi ����)
                        cout << endl;
                    }
                }
            }
        }
    }
}

void CLA::print_table_basic(int x) {                            // ���̺� ǥ �⺻ 0�� 1 ��� �Լ�
    for (int i = 0; i < 16; i++) {
        if (table_array_row[i] != -1) {                         // table_row�� �����ϴ� ������ ���
            array_x[table_array_row[i]] = 0;                    // array_x�� 0 ����
        }
    }

    for (int i = 0; i < 4; i++) {
        if (table_array_col[x][i] != -1) {                      // �ش� table_col�� ������ ���
            for (int j = 0; j < 16; j++) {
                if (table_array_row[j] == table_array_col[x][i]) {  // table_col�� row�� ������ (�ּ��׿� ���Ե��ִ� ���)
                    array_x[table_array_col[x][i]] = 1;             // array_x�� 1 ���� ('x' ���)
                }
            }
        }
    }
}
void CLA::print_table_x(int x) {                                // ù ��° ���̺� ǥ ��� �Լ�
    print_table_basic(x);                                       // ���̺� ǥ�� 0�� 1 ����
    cout << " ";
    for (int i = 0; i < 16; i++) {
        if (array_x[i] != -1) {                                 // ���� ������ ���
            if (i > 9) {
                if (array_x[i] == 0) cout << "    ";            // 0�̸� ���� ���
                if (array_x[i] == 1) cout << "  x ";            // 1�̸� x ���
            }
            else {
                if (array_x[i] == 0) cout << "   ";
                if (array_x[i] == 1) cout << " x ";
            }
        }
    }
}

void CLA::print_table_x2(int x) {                               // �� ��° ���̺� ǥ ��� �Լ� (ù ��° epi ����)
    print_table_basic(x);                                       // ���̺� ǥ�� 0�� 1 ����
    select_pi_key(x);                                           // ù ��° epi Ű ����
    cout << " ";
    for (int i = 0; i < 16; i++) {
        if (array_x[i] != -1) {                                 // ���� ������ ���
            if (i > 9) {
                if (array_x[i] == 0) cout << "    ";            // 0�̸� ���� ���
                if (array_x[i] == 1) cout << "  x ";            // 1�̸� x ���
                if (array_x[i] == 2) {                          // 2�̸� �� ���
                    cout << " �� ";
                    removeDouble(x);                            // essential �迭 �ݺ� ����
                }
            }
            else {
                if (array_x[i] == 0) cout << "   ";
                if (array_x[i] == 1) cout << " x ";
                if (array_x[i] == 2) {
                    cout << " ��";   // ��  
                    removeDouble(x);
                }
            }
        }
    }
}

void CLA::print_table_x3(int x) {                                // ���� ���̺� ǥ ��� �Լ� (�߰� epi ����)
    int add_array[4] = { -1, -1, -1, -1 };
    int index = 0, count = 0;
    print_table_basic(x);                                       // ���̺� ǥ�� 0�� 1 ����
    select_pi_key(x);                                           // ù ��° epi Ű ����
    select_pi_key_2(x);                                         // �߰� epi Ű ����

    for (int i = 0; i < 16; i++) {
        if (array_x[i] == 1) {                                  // -�� �ٲ� �� ���� �ּ��׿� ����ִ� �� ���� �޾ƿͼ�
            add_array[index] = i;                               // �ּ����� add_array�� ����
            index += 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (table_array_col[x][2] != -1) {                      // 3��° ���� ������ ��� (second_num�� �ּ���)
            if (add_array[i] == table_array_col[x][i] && add_array[i] != -1) {  // �ּ��װ� ���� �ּ����� ������
                count += 1;                                                     // count ����
            }
        }
        else {
            if (add_array[i] == table_array_col[x][i] && add_array[i] != -1) {  // 3��° ���� �������� ���� ��� (first_num�� �ּ���)
                count += 2;                                                     // count 2�� ����
            }
        }
    }
    if (count == 4) {                                   // ���� ��Ƴ��Ҵٰ� �Ǻ��ȴٸ�
        for (int i = 0; i < 4; i++) {
            array_x[add_array[i]] = 2;                  // array_x�� 2(��)�� �ٲ��ֱ�
        }
    }
    cout << " ";
    for (int i = 0; i < 16; i++) {
        if (array_x[i] != -1) {                                 // ���� ������ ���
            if (i > 9) {
                if (array_x[i] == 0) cout << "    ";            // 0�̸� ���� ���
                if (array_x[i] == 1) cout << "  x ";            // 1�̸� x ���
                if (array_x[i] == 2) {                          // 2�̸� �� ���
                    cout << " �� ";
                    removeDouble(x);                            // essential �迭 �ݺ� ����
                }
                if (array_x[i] == 3) cout << "  - ";            // 3�̸� - ���
            }
            else {
                if (array_x[i] == 0) cout << "   ";
                if (array_x[i] == 1) cout << " x ";
                if (array_x[i] == 2) {
                    cout << " ��";
                    removeDouble(x);
                }
                if (array_x[i] == 3) cout << " - ";
            }
        }
    }
}
void CLA::print_table_space(int x) {                // ���̺� ǥ���� �ڸ����� ���� ���� ��� �Լ�
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

int CLA::next_skip() {                  // ���� ȭ������ �Ѿ�� �Լ�
    int input = 0, move_check = 0;

    while (input != 32) {
        if (_kbhit() == true) {        // Ű���� �Է� Ȯ�� (true / false)
            input = _getch();
            if (input == 0x00 || input == 0xE0)
                input = _getch();
            if (input == 32) {          // Ű���尡 �Էµ� ���
                move_check = 1;         // ���� �� 1�� ����
                break;
            }
        }
    }
    return move_check;                  // ������ ��ȯ
}