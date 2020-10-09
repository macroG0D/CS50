const changeHead = function(){
    let hrefLength = window.location.href.length;
    let page = window.location.href[hrefLength-1];
    try {
        document.querySelector(".dynamic-header").textContent = `Week ${page}`;
        document.querySelector("title").textContent = `CS50: Week ${page}`;
    }
    catch(err) {
      document.querySelector("h1").textContent = `This is CS50!`;
      console.log('main page');
    }

}

changeHead()