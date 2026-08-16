def monitor_following_distance(distances: list[float], speeds: list[float]) -> tuple[int, float, int]:
    if not distances:
        MIN_DIS=0.0
    else:
        MIN_DIS=distances[0]
    
    TAILGATING_SEC=0
    TAILGATE_INC=0
    TAILGATE_PREVIOUS_STATE=False
    TAILGATE_CURRENT_STATE=False
    SAFE_DIS=0.0
    for i in range(len(distances)):
            
        SAFE_DIS=speeds[i]*0.5
        if distances[i]<  MIN_DIS:
            MIN_DIS=distances[i]
        
           
        if  distances[i]<  SAFE_DIS:
            TAILGATING_SEC=TAILGATING_SEC+1
            TAILGATE_CURRENT_STATE=True
        else:
            TAILGATE_CURRENT_STATE=False
        if TAILGATE_PREVIOUS_STATE==False and TAILGATE_CURRENT_STATE==True:
            TAILGATE_INC=TAILGATE_INC+1
            TAILGATE_PREVIOUS_STATE=TAILGATE_CURRENT_STATE
            
        else:
            TAILGATE_PREVIOUS_STATE=TAILGATE_CURRENT_STATE
            
    
    return (TAILGATING_SEC,MIN_DIS,TAILGATE_INC)
