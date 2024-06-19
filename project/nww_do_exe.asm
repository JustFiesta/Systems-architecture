         [bits 32]

; Inicjalizacja stosu i wywo≥anie pobierania pierwszej liczby
;        esp -> [ret]  ; ret - adres powrotu do asmloader
extern   _printf
extern   _scanf
extern   _exit

section  .bss

section .text

global _main

_main:
         call geta

fora:     
          db "a = ", 0
geta:
;        esp -> [fora][ret]
         call _printf

;        esp -> [a][ret]

         push esp

;        esp -> [addr_a][a][ret]

         call geta2
fora2:    
          db "%i", 0
geta2:
;        esp -> [fora2][addr_a][a][ret]
         call _scanf
         
         add esp, 2*4
;        esp -> [a][ret]

         pop esi;
         mov eax, esi
         ;      esi = a
;        esp -> [ret]

; Pobieranie drugiej liczby
         call getb
forb:     
          db "b = ", 0
getb:

;        esp -> [forb][ret]
         call _printf
         
;        esp -> [b][ret]

         push esp

;        esp -> [addr_b][b][ret]

         call getb2
forb2:    
          db "%i", 0
getb2:
;        esp -> [forb2][addr_b][b][ret]
         call _scanf
         
         add esp, 2*4
         
;        esp -> [b][ret]

         pop edi
         push edi
         push esi

         push esi;     esp -> [esi][esi][edi][ret]
         push edi;     esp -> [edi][esi][ret]

         call wypisz

; Wyúwietlanie formatu NWW
format:
          db "NWW(%i,%i) = ", 0
wypisz:
;        esp -> [format][edi][esi][ret]
         call _printf
         
         add esp, 3*4
;        esp -> [ret]

; Algorytm obliczania NWW
start:
         cmp esi, edi
         je koniec
         ja opcja1
         
         sub edi, esi
         jmp start


opcja1:
         sub esi, edi
         jmp start

; Wyjúcie i wyúwietlenie wyniku
koniec:
         pop eax

         div esi
         
         pop ecx
         
         mul ecx
         push eax;     esp -> [esi][ret]
         call wypisz2
format2:
          db "%i", 0xA, 0
wypisz2:

;       esp -> [format2][esi][ret]
        call _printf

        add esp, 2*4
;       esp -> [ret]

        push 0
        
        call _exit


; asmloader API
;
; ESP wskazuje na prawidlowy stos
; argumenty funkcji wrzucamy na stos
; EBX zawiera pointer na tablice API
;
; call [ebx + NR_FUNKCJI*4] ; wywolanie funkcji API
;
; NR_FUNKCJI:
;
; 0 - exit
; 1 - putchar
; 2 - getchar
; 3 - printf
; 4 - scanf
;
; To co funkcja zwr√≥ci jest w edi.
; Po wywolaniu funkcji sciagamy argumenty ze stosu.
;
; https://gynvael.coldwind.pl/?id=387```