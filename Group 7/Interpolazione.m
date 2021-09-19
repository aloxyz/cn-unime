%(A) Verificare la bontà del metodo di interpolazione di Lagrange (o di Newton) su alcune
% funzioni, di cui si conosce la formula analitica, considerando tabulati con 5, 6, 11, 12, 20, 25
% punti equidistanti. Analizzare il grafico degli errori. 


tabs = {{{{},{}},{},{}},    %5 punti: {{{x base},{y base}},{polinomio},{y calcolate}}
        {{{},{}},{},{}},    % //
        {{{},{}},{},{}},    % //
        {{{},{}},{},{}}, 
        {{{},{}},{},{}}, 
        {{{},{}},{},{}},    % //
        {{},{}}};           % {{x graficazione},{y graficazione vere}}
    
%In questo caso func3 = func2 solo che in intervalli diversi
tabulati = {{tabs, tabs, tabs}, {tabs, tabs, tabs}}; %{punti equidistanti: {func1, func2, func3}, 
sizes = [5, 6, 11, 12, 20, 25];                      % punti non equidistanti: {func1, func2, func3}}   
range1 = [-1, 1];
range2 = [-10, 10];

for i = 1:6 %crea i tabulati di punti
    for j = 1:2
        for k = 1:3
        tabulati{j}{k}{i}{1}{2} = ones(sizes(i),1);        
        end
    end
    
    for k = 1:3
        tabulati{2}{k}{i}{1}{1} = ones(sizes(i),1);
    end
    %Inizializza le x equidistnati dei punti di interpolazione
    tabulati{1}{1}{i}{1}{1} = linspace(range1(1), range1(2), (sizes(i)));
    tabulati{1}{2}{i}{1}{1} = linspace(range1(1), range1(2), (sizes(i)));
    tabulati{1}{3}{i}{1}{1} = linspace(range2(1), range2(2), (sizes(i)));
    
    %Inizializza le x non equidistanti dei punti di interpolazione
    for j = 1:sizes(i)
            tabulati{2}{1}{i}{1}{1}(j) = points1(j, sizes(i));
            tabulati{2}{2}{i}{1}{1}(j) = points1(j, sizes(i));
            tabulati{2}{3}{i}{1}{1}(j) = points2(j, sizes(i), range2(1), range2(2));
    end
    
    %Calcola le y delle funzioni nei punti di interpolazione
    for k = 1:2
        for j = 1:sizes(i)
            tabulati{k}{1}{i}{1}{2}(j) = func1(tabulati{k}{1}{i}{1}{1}(j));
            tabulati{k}{2}{i}{1}{2}(j) = func2(tabulati{k}{2}{i}{1}{1}(j));
            tabulati{k}{3}{i}{1}{2}(j) = func2(tabulati{k}{3}{i}{1}{1}(j));
        end
    
        %Calcola il polinomio di Lagrange
        for j = 1:3
            tabulati{k}{j}{i}{2} = Lagrange(tabulati{k}{j}{i}{1}{1},tabulati{k}{j}{i}{1}{2});
        end
    end
end

%Inizializza le x di graficazione delle 3 funzioni
points = 200;
for k = 1:2
    for i = 1:3
        tabulati{k}{i}{7}{1} = [];
        for j = 1:6 
            %Fa in modo che nelle x di graficazione ci siano tutte le x base d'interpolazione
            %della funzione attuale
            tabulati{k}{i}{7}{1} = union(tabulati{k}{i}{7}{1}, tabulati{k}{i}{j}{1}{1});
        end
    end
end

for k = 1:2
%Fa in modo che le x di graficazione siano esattamente quante scelte in
%"points" e che le x della base di interpolazione siano incluse
tabulati{k}{1}{7}{1} = union(linspace(range1(1), range1(2), points-max(size(tabulati{k}{1}{7}{1}))), tabulati{k}{1}{7}{1});
tabulati{k}{2}{7}{1} = union(linspace(range1(1), range1(2), points-max(size(tabulati{k}{2}{7}{1}))), tabulati{k}{2}{7}{1});
tabulati{k}{3}{7}{1} = union(linspace(range2(1), range2(2), points-max(size(tabulati{k}{3}{7}{1}))), tabulati{k}{3}{7}{1});

end
%Inizializza le y delle 3 funzioni
for k = 1:2    
    for i = 1:3
        tabulati{k}{i}{7}{2} = ones(1, max(size(tabulati{k}{i}{7}{1})));
    end
end

for k = 1:2
    %Calcola le y delle 3 funzioni nei punti di graficazione
    for j = 1:max(size(tabulati{k}{1}{7}{1}))
        tabulati{k}{1}{7}{2}(j) = func1(tabulati{k}{1}{7}{1}(j));
    end

    for j = 1:max(size(tabulati{k}{2}{7}{1}))
        tabulati{k}{2}{7}{2}(j) = func2(tabulati{k}{2}{7}{1}(j));
    end

    for j = 1:max(size(tabulati{k}{3}{7}{1}))
        tabulati{k}{3}{7}{2}(j) = func2(tabulati{k}{3}{7}{1}(j));
    end
end

%Calcola il valore di ogni y di graficazione per ogni polinomio interpolatore
for k = 1:2
    for i = 1:3
        n = max(size(tabulati{k}{i}{7}{1}));
        for j = 1:6
            tabulati{k}{i}{j}{3} = ones(1,n);
            for z = 1:n
                tabulati{k}{i}{j}{3}(z) = solve(tabulati{k}{i}{7}{1}(z), tabulati{k}{i}{j}{2}); 
            end
        end
    end
end

%Plotta f(x) e p(x)
for k = 1:2
    for i = 1:3
        figure(i + 3*(~mod(k,2)));
        for j = 1:6
            subplot(3,2,j)
            plot(tabulati{k}{i}{7}{1}, tabulati{k}{i}{7}{2}, 'r');
            hold on
            plot(tabulati{k}{i}{7}{1}, tabulati{k}{i}{j}{3}, 'b');
            plot(tabulati{k}{i}{j}{1}{1}, tabulati{k}{i}{j}{1}{2}, 'k*');

            ylim([min(min(tabulati{k}{i}{7}{2}),min(tabulati{k}{i}{j}{3})), max(max(tabulati{k}{i}{7}{2}),max(tabulati{k}{i}{j}{3}))])
            xlim([min(tabulati{k}{i}{7}{1}), max(tabulati{k}{i}{7}{1})]);
            if k == 1
                title("Punti equidistanti: Polinomio di grado", max(size(tabulati{k}{i}{j}{2}))-1);
            else
                title("Punti non equidistanti: Polinomio di grado", max(size(tabulati{k}{i}{j}{2}))-1);
            end
        end
        legend("f(x)", "p(x)", "punti di interpolazione");
        
    end
end

norma_errori = ones(6,3);
norma_errori = {norma_errori,norma_errori};
%Plotta gli errori
for j = 1:3
   figure(6+j)
   for k = 1:2
        subplot(2,1,k)
        colors = ['r', 'b', 'g', 'y', 'k', 'm'];
        names = [];
        massimo = 0;
        for i = 1:6
            errore = abs((tabulati{k}{j}{7}{2} - tabulati{k}{j}{i}{3}));  
            plot(tabulati{k}{j}{7}{1}, errore, colors(i));
            hold on 
            
            norma_errori{k}(i,j) = norm(errore, 2);
            
            if massimo < max(errore)
                massimo = max(errore);
            end
            names = [names, "Grado " + (max(size(tabulati{k}{j}{i}{2}))-1)];
            
            if k == 1
                title("Punti equidistanti");
            else
                title("Punti non equidistanti");
            end
        end
        legend(names);
        xlim([min(tabulati{k}{j}{7}{1}), max(tabulati{k}{j}{7}{1})]);
        ylim([0, massimo]);
   end
end

uitable(figure(10), 'Data', norma_errori{1}, 'ColumnName',1:3, 'RowName', (sizes-1));
title("Norma errori: punti equidistanti")

uitable(figure(11), 'Data', norma_errori{2}, 'ColumnName',1:3, 'RowName', (sizes-1));
title("Norma errori: punti non equidistanti")

function y = func1(x)       %definita in [-1, 1]
    y = 1/(1 + 25 * x * x);

end

function y = func2(x)       %definita in [-10,10] e [-1, 1]
    y = x/(1 + x * x);
end


function coeff = Lagrange(x,y) %Funzione che dati i punti di interpolazione
n = max((size(x)));            %restituisce il polinomio interpolatore 
coeff = zeros(1,n);            %sottoforma di vettore 
    for i = 1:n                %utilizzando l'interpolazione di Lagrange 
        tmp = [1];
        %Varia j da 1 a n per j diverso da i
        for j = 1:i-1
            tmp1 = tmp;
            %Viene scomposto tmp*(x-xj) in tmp*x - tmp*xj
            for k = max(size(tmp)):-1:1
                tmp(k+1)= tmp(k);           %Moltiplica tmp per x (sposta ogni elemento a destra)
                tmp1(k) = tmp1(k) * x(j);   %Moltiplica ogni elemento per xj cambiando di segno
            end
            tmp(1) = 0; %Gli elementi sono stati spostati a destra ed è 
                        %necessario che il primo venga azzerato
            
            tmp1 = [tmp1, 0]; %Il vettore viene allargato per far sì che combacino le dimensioni con tmp

            tmp = tmp - tmp1;               
            tmp = tmp/(x(i)-x(j));
        end
        for j = i+1:n
            tmp1 = tmp;
            for k = max(size(tmp)):-1:1
                tmp(k+1)= tmp(k);
                tmp1(k) = tmp1(k) * x(j);
            end
            tmp(1) = 0;
            tmp1 = [tmp1, 0];
            tmp = tmp - tmp1;
            tmp = tmp/(x(i)-x(j));          
        end
        coeff = coeff + (tmp * y(i));
    end
coeff = coeff(1:find(coeff, 1, 'last'));
end

function y  = solve(x, polynomial)  %Ruffini-Horner
    %a + bx + cx^2 + dx^3 = a+x(b + x(c + dx)
    n = max(size(polynomial));
    y = polynomial(n);
    
    for i = n-1: -1: 1
        y = x*y + polynomial(i);
    end
end

function x = points1(i,n)
    x = cos(((2*(n-i)+1)*pi)/(2*(n+1)));
end

function x = points2(i,n,a,b)
    x = points1(i,n);
    x = (b-a)/2*x+(b+a)/2; 
end