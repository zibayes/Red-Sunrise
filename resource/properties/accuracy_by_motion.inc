(define "accuracy_by_motion" ;  spreading depending on the speed of "body", "gun" volumes
	{AccuracyByMotion
        {MaxLinearSpeed %max_linear}               ;km/h
        {ByLinearSpeed %accuracy_by_linear}
        {MaxAngularSpeed %max_angular}             ;deg/s
        {ByAngularSpeed %accuracy_by_angular}
        {DisorderTime %disorder_time}              ;s
        {OrderTime %order_time}                    ;s
    }
)

(define "abm_low"
    ("accuracy_by_motion"
        max_linear(7) accuracy_by_linear(0.3)
        max_angular(4) accuracy_by_angular(0.4)
        disorder_time(1.0) order_time(2.0)
    )
)
(define "abm_medium"
    ("accuracy_by_motion"
        max_linear(8) accuracy_by_linear(0.35)
        max_angular(4) accuracy_by_angular(0.4)
        disorder_time(1.0) order_time(2.0)
    )
)
(define "abm_high"
    ("accuracy_by_motion"
        max_linear(9) accuracy_by_linear(0.4)
        max_angular(4) accuracy_by_angular(0.4)
        disorder_time(1.0) order_time(2.0)
    )
)
(define "abm_veteran"
    ("accuracy_by_motion"
        max_linear(9) accuracy_by_linear(0.4)
        max_angular(4) accuracy_by_angular(0.4)
        disorder_time(1.5) order_time(1.5)
    )
)
(define "abm_ace"
    ("accuracy_by_motion"
        max_linear(9) accuracy_by_linear(0.4)
        max_angular(4) accuracy_by_angular(0.5)
        disorder_time(2.0) order_time(1.0)
    )
)
(define "abm_shoulder_stop" ; Плечевой стабилизатор
    ("accuracy_by_motion"
        max_linear(10) accuracy_by_linear(0.5)
        max_angular(4) accuracy_by_angular(0.5)
        disorder_time(1.0) order_time(1.0)
    )
)
(define "abm_stabilized" ; Базовый стабилизатор
    ("accuracy_by_motion"
        max_linear(12) accuracy_by_linear(0.75)
        max_angular(4) accuracy_by_angular(0.6)
        disorder_time(1.5) order_time(1.0)
    )
)
(define "abm_stabilized_twoplane_basic" ; Базовый двухплоскостной стабилизатор
    ("accuracy_by_motion"
        max_linear(14) accuracy_by_linear(0.75)
        max_angular(8) accuracy_by_angular(0.7)
        disorder_time(2.0) order_time(1.0)
    )
)

(define "abm_stabilized_twoplane" ; Двухплоскостной стабилизатор
    ("accuracy_by_motion"
        max_linear(15) accuracy_by_linear(0.75)
        max_angular(10) accuracy_by_angular(0.7)
        disorder_time(2.5) order_time(1.0)
    )
)

(define "abm_stabilized_twoplane_advanced" ; Продвинутый двухплоскостной стабилизатор
    ("accuracy_by_motion"
        max_linear(15) accuracy_by_linear(0.85)
        max_angular(12) accuracy_by_angular(0.8)
        disorder_time(2.5) order_time(0.5)
    )
)

(define "abm_zenite"
    ("accuracy_by_motion"
        max_linear(15) accuracy_by_linear(0.3)
        max_angular(4) accuracy_by_angular(0.8)
        disorder_time(1.2) order_time(1.4)
    )
)
(define "abm_howitzer"
    ("accuracy_by_motion"
        max_linear(5) accuracy_by_linear(0.5)
        max_angular(5) accuracy_by_angular(0.5)
        disorder_time(0) order_time(5.0)
    )
)

(define "abm_mgun"
	("accuracy_by_motion"
		max_linear(16) accuracy_by_linear(0.5)
		max_angular(4) accuracy_by_angular(0.8)
		disorder_time(1.2) order_time(2.0)
	)
)
(define "abm_mgun_heavy"
	("accuracy_by_motion"
		max_linear(16) accuracy_by_linear(0.5)
		max_angular(4) accuracy_by_angular(0.9)
		disorder_time(1.2) order_time(2.0)
	)
)
(define "abm_mgun_stabilized"
	("accuracy_by_motion"
		max_linear(16) accuracy_by_linear(0.75)
		max_angular(15) accuracy_by_angular(0.9)
		disorder_time(0.25) order_time(0.25)
	)
)
(define "abm_mgun_stabilized_advanced"
	("accuracy_by_motion"
		max_linear(18) accuracy_by_linear(0.85)
		max_angular(16) accuracy_by_angular(0.9)
		disorder_time(0.25) order_time(0.25)
	)
)