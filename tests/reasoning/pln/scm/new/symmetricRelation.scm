; Adapted from bigdemo.scm by JaredW
(ForAllLink (stv 0.99000001 0.99000001)
    (ListLink (stv 1 0)
        (VariableNode "X007" (stv 1 0))
        (VariableNode "X008" (stv 1 0))
        (VariableNode "R000" (stv 1 0)))
    (ImplicationLink (stv 1 0)
        (AndLink (stv 1 0)
            (InheritanceLink (stv 1 0)
                (VariableNode "R000" (stv 1 0))
                (ConceptNode "symmetricRelation" (stv 1 0))
             )
            (EvaluationLink (stv 1 0)
                (VariableNode "R000" (stv 1 0))
                (ListLink (stv 1 0)
                    (VariableNode "X007" (stv 1 0))
                    (VariableNode "X008" (stv 1 0))
                )
            )
        )
        (EvaluationLink (stv 1 0)
            (VariableNode "R000" (stv 1 0))
            (ListLink (stv 1 0)
                (VariableNode "X008" (stv 1 0))
                (VariableNode "X007" (stv 1 0))))))

(EvaluationLink (stv 0.80000001 0.2) (PredicateNode "friendOf" (stv 1 0))
    (ListLink (stv 1 0) (ConceptNode "Bill" (stv 1 0))
       (ConceptNode "Ted" (stv 1 0))))

(InheritanceLink (stv 0.99900001 0.99900001) (PredicateNode "friendOf" (stv 1 0))
    (ConceptNode "symmetricRelation" (stv 1 0)))

(define t (EvaluationLink (PredicateNode "friendOf")
    (ListLink (ConceptNode "Ted")
       (ConceptNode "Bill"))))
