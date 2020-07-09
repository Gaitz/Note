

function h1 () {
  const h1 = document.createElement('h1')

  h1.innerText = "hello webpack"

  return h1
}

document.body.appendChild(h1())