interface ItemElement
{
    public int accept(ShoppingCartVisitor visitor);
}

class Book implements ItemElement
{
    private int price;
    private String isbnNumber;
 
    public Book(int cost, String isbn)
    {
        this.price=cost;
        this.isbnNumber=isbn;
    }
 
    public int getPrice() 
    {
        return price;
    }
 
    public String getIsbnNumber() 
    {
        return isbnNumber;
    }
 
    @Override
    public int accept(ShoppingCartVisitor visitor) 
    {
        return visitor.visit(this);
    }
 
}

class Fruit implements ItemElement 
{
    private int pricePerKg;
    private int weight;
    private String name;
 
    public Fruit(int priceKg, int wt, String nm)
    {
        this.pricePerKg=priceKg;
        this.weight=wt;
        this.name = nm;
    }
 
    public int getPricePerKg() 
    {
        return pricePerKg;
    }
 
    public int getWeight() 
    {
        return weight;
    }
 
    public String getName()
    {
        return this.name;
    }
 
    @Override
    public int accept(ShoppingCartVisitor visitor) 
    {
        return visitor.visit(this);
    }
 
}

interface ShoppingCartVisitor 
{
 
    int visit(Book book);
    int visit(Fruit fruit);
}

class ShoppingCartVisitorImpl implements ShoppingCartVisitor
{
 
    @Override
    public int visit(Book book)
    {
        int cost=0;
        //apply 5$ discount if book price is greater than 50
        if(book.getPrice() &gt; 50)
        {
            cost = book.getPrice()-5;
        }
        else 
            cost = book.getPrice();
            
        System.out.println(&quot;Book ISBN::&quot;+book.getIsbnNumber() + &quot; cost =&quot;+cost);
        return cost;
    }
 
    @Override
    public int visit(Fruit fruit) 
    {
        int cost = fruit.getPricePerKg()*fruit.getWeight();
        System.out.println(fruit.getName() + &quot; cost = &quot;+cost);
        return cost;
    }
 
}

class ShoppingCartClient 
{
 
    public static void main(String[] args) 
    {
        ItemElement[] items = new ItemElement[]{new Book(20, &quot;1234&quot;),
                              new Book(100, &quot;5678&quot;), new Fruit(10, 2, &quot;Banana&quot;),
                              new Fruit(5, 5, &quot;Apple&quot;)};
 
        int total = calculatePrice(items);
        System.out.println(&quot;Total Cost = &quot;+total);
    }
 
    private static int calculatePrice(ItemElement[] items) 
    {
        ShoppingCartVisitor visitor = new ShoppingCartVisitorImpl();
        int sum=0;
        for(ItemElement item : items)
        {
            sum = sum + item.accept(visitor);
        }
        return sum;
    }
 
}


/* 
Output

Book ISBN::1234 cost =20
Book ISBN::5678 cost =95
Banana cost = 20
Apple cost = 25
Total Cost = 160
*/