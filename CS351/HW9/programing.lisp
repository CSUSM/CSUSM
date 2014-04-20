#!/usr/bin/env clisp

; p.724 n.4
(defun riseToPower (A B)
  (if (= B 0) (return-from riseToPower 1))
  (return-from riseToPower (* A (riseToPower A (- B 1))))
)

(print "Testing p.724 n.4. Expected: T, T")
(print (= 1 (riseToPower 10 0)))
(print (= 32 (riseToPower 2 5)))


; p. 724 n.5
(defun countZeros (args)
  (if (eq nil (car args)) (return-from countZeros 0))
  (if (= 0 (car args)) (return-from countZeros (+ 1 (countZeros (cdr args)))))
  (return-from countZeros (countZeros (cdr args)))
)

(print "Testing p.724 n.5. Expected: 4, 1, 0")
(print (countZeros (list 0 0 0 0)))
(print (countZeros (list 42 51 69 0)))
(print (countZeros (list 4)))

; p. 725 n.12
(defun isStructEqual (l1 l2)
  (if (and (eq nil (car l1)) (eq nil (car l2)))
    (return-from isStructEqual T))
  (if (or (eq nil (car l1)) (eq nil (car l2)))
      (return-from isStructEqual nil))
  (return-from isStructEqual (isStructEqual (cdr l1) (cdr l2)))
)

(print "Testing p.724 n.12. Expected: T, T, nil, nil")
(print (isStructEqual (list 0 0 0 0) (list 0 0 0 0)))
(print (isStructEqual (list 0 0 0 0) (list 42 42 42 42)))
(print (isStructEqual (list 0 0 0 0) (list 0 0 0)))
(print (isStructEqual (list 0 0 0 0) (list 0 0 0 0 0)))
