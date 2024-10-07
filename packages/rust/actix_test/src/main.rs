use actix_session::Session;
use actix_session::{storage::CookieSessionStore, SessionMiddleware};
use actix_web::{get, Responder};
use actix_web::{App, HttpServer};

#[get("/session")]
async fn session(session: Session) -> impl Responder {
    let counter = match session.get::<i32>("counter") {
        Ok(counter) => match counter {
            Some(counter) => counter + 1,
            _ => 1,
        },
        _ => 1,
    };

    match session.insert("counter", counter) {
        _ => format!("You have visited {} times", counter),
    }
}

static SESSION_SIGNING_KEY: &[u8] = &[0; 64]; // Just an example

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    let key = actix_web::cookie::Key::from(SESSION_SIGNING_KEY);

    let host = "0.0.0.0";
    let port = 80;
    HttpServer::new(move || {
        App::new()
            .wrap(
                SessionMiddleware::builder(CookieSessionStore::default(), key.clone())
                    .cookie_secure(false)
                    .build(),
            )
            .service(session)
    })
    .bind((host, port))?
    .run()
    .await
}