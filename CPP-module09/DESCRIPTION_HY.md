                 ./btc input.txt
                       │
                       ▼
                    main()
                       │
             argc == 2 ? ─── NO → error
                       │
                      YES
                       │
                       ▼
             BitcoinExchange exchange
                       │
                       ▼
          LoadDataBase("data.csv")
                       │
                       ▼
                  _database
                       │
                       │
          ProcessFile("input.txt")
                       │
                       ▼
                 read each line
                       │
             ┌─────────┴─────────┐
             ▼                   ▼
          date                 value
             │                   │
             ▼                   ▼
      isValidDate()        parseValue()
             │                   │
             └─────────┬─────────┘
                       ▼
                  findRate()
                       │
                       ▼
                 value × rate
                       │
                       ▼
                    output

