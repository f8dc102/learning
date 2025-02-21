bulgogiPizzaCount = int(input("불고기 피자 조각 수: "))
hawaiiPizzaCount = int(input("하와이안피자 조각 수: "))

print("피자를 나눌 수 있는가?", hawaiiPizzaCount % 2 == 0 and  bulgogiPizzaCount % 2 == 0)
