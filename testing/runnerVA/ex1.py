def getNetProfit(events):
    portfolio = {}  # Dictionary to store stock quantities
    stock_prices = {}  # Dictionary to store stock prices
    result = []  # List to store profit from QUERY events
    profit = 0

    for event in events:
        parts = event.split()  # Split the event into parts
        if parts[0] == "BUY":
            stock = parts[1]  # Get the stock name
            quantity = int(parts[2])  # Get the quantity of stocks purchased
            portfolio[stock] = portfolio.get(stock, 0) + quantity  # Update the portfolio
        elif parts[0] == "SELL":
            stock = parts[1]  # Get the stock name
            quantity = int(parts[2])  # Get the quantity of stocks sold
            portfolio[stock] -= quantity  # Update the portfolio by reducing sold stocks
            profit += stock_prices[stock] * quantity  # Calculate profit from sold stocks
        elif parts[0] == "CHANGE":
            stock = parts[1]  # Get the stock name
            price_change = int(parts[2])  # Get the change in stock price
            stock_prices[stock] = stock_prices.get(stock, 0) + price_change  # Update stock price
            profit += portfolio.get(stock, 0) * price_change  # Calculate profit from price change
        elif parts[0] == "QUERY":
            result.append(profit)  # Append the current profit to the result list

    return result

# Sample Input
events = ["BUY hackr 65", "QUERY"]
# Output: [0]
print(getNetProfit(events))