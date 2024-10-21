#include <iostream>

int main() {
    long factorials[8]; // ����� ��� ��������� ���������

    __asm {
        mov EDX, 1               // ˳������� ��� n, �������� � 1
        mov ECX, 8               // ʳ������ �������� (��������� �� 1 �� 8)
        lea EBX, factorials      // ������ ������ ���������

        calc_factorial :
        mov EAX, 1               // ���������� EAX ��� ���������� ��������� (��������� �������� ��������� ��� n)
            mov ESI, EDX             // ������� n � ESI (�� ���� ������� ����� ��� ���������� ���������)

            factorial_loop :
        imul EAX, ESI            // EAX = EAX * ESI (������� �� ������� n)
            dec ESI                  // �������� n
            jnz factorial_loop       // ����������� �� �����, ���� n > 0

            mov[EBX], EAX           // �������� ��������� � ����� (EAX ������ �������� ��� ��������� �����)
            add EBX, 4               // ���������� �� �������� ������� ������ (4 ����� ��� ������� �������� ������)
            inc EDX                  // �������� n ��� ���������� ���������
            loop calc_factorial      // �������� ECX � ����������, ���� ECX != 0
    }

    // ��������� ����������
    std::cout << "��������� ����� �� 1 �� 8:" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << "F(" << (i + 1) << ") = " << factorials[i] << std::endl;
    }

    return 0;
}



