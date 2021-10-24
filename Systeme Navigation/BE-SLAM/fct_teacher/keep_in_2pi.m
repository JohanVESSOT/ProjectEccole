function x = keep_in_2pi(x)

if(x>pi)
    while(x>pi)
        x=x-2*pi;
    end
elseif(x<-pi)
    while(x<-pi)
        x = x+2*pi;
    end
end